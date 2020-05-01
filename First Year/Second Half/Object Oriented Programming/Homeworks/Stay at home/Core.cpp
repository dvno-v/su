 #ifndef CORE_CPP

#define CORE_CPP

#include "Core.h"
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>

const unsigned MAX_CHALLENGE_NAME_LENGTH = 32;

void Core::delete_part_of_core_memory(char const* to_delete) {
    if (strcmp(to_delete, "users") == 0) {
        // std::cout << "deleted email\n"; 
        delete[] this->users;
    }
    if (strcmp(to_delete, "challenges") == 0) {
        // std::cout << "deleted challenges\n"; 
        delete[] this->known_challenges;
    }
}

int Core::get_challenge_index(const char* challenge_name) const {
    for (unsigned i = 0; i < this->challenges_size; i++)
    {
        if (strcmp(this->known_challenges[i]->get_challenge_name(), challenge_name) == 0) {
            return i;
        }
    }
    return -1;
}


void Core::add_challenge_to_core(Challenge* to_add) {
    Challenge** temp = new Challenge * [this->challenges_size + 1];

    for (unsigned i = 0; i < this->challenges_size; i++)
    {
        temp[i] = this->known_challenges[i];
    }

    temp[this->challenges_size++] = to_add;
    this->delete_part_of_core_memory("challenges");
    this->known_challenges = temp;
}

void Core::add_user(User* a) {
    User** temp = new User * [this->users_size + 1];
    for (size_t i = 0; i < this->users_size; i++)
    {
        temp[i] = this->users[i];
    }
    this->delete_part_of_core_memory("users");
    temp[this->users_size++] = a;
    this->users = temp;
}

bool Core::is_valid_challenge(const Tokens& t) const
{
    if(strlen(t.tokens[2]) > MAX_CHALLENGE_NAME_LENGTH || *(t.tokens[2]) != '#')
        return false;
    return true;
}

int Core::get_user_index(const char* name) const {
    for (unsigned i = 0; i < this->users_size; i++)
    {
        if (strcmp(this->users[i]->get_name(), name) == 0) return i;
    }
    return -1;
}

Core::Core() {
    this->users = nullptr;
    this->users_size = 0;
    this->known_challenges = nullptr;
    this->challenges_size = 0;
}

Core::Core(User** _users, unsigned _number_of_users) {
    for (unsigned i = 0; i < _number_of_users; i++)
    {
        this->add_user(_users[i]);
    }
    this->users_size = _number_of_users;
}

Core::Core(Challenge** _challenges, unsigned _challenges_size) {
    for (unsigned i = 0; i < _challenges_size; i++)
    {
        this->add_challenge_to_core(_challenges[i]);
    }
    this->challenges_size = _challenges_size;
}

Core::Core(User** _users, unsigned _number_of_users, Challenge** _challenges, unsigned _challenges_size) {
    for (unsigned i = 0; i < _number_of_users; i++)
    {
        this->add_user(_users[i]);
    }
    this->users_size = _number_of_users;

    for (unsigned i = 0; i < _challenges_size; i++)
    {
        this->add_challenge_to_core(_challenges[i]);
    }
    this->challenges_size = _challenges_size;
}

Core::Core(const Core& _other)
{
    std::cout << "Ah ti piratche takova, ne moje da mi pipash qdroto!!!\n";
}


void Core::operator=(const Core&)
{
    std::cout << "Pak se opitvash. Ne moje da mi kopirash qdroto\n";
}

Core::~Core() {
    for (unsigned i = 0; i < this->users_size; i++)
    {
        std::cout << "deleting user-" << i + 1 << '\n';
        delete this->users[i];
    }
    std::cout << "deleting users array\n";
    this->delete_part_of_core_memory("users");
    for (unsigned i = 0; i < this->challenges_size; i++)
    {
        std::cout << "deleting challenge-" << i + 1 << '\n';
        delete this->known_challenges[i];
    }
    std::cout << "deleting challenges array\n";
    this->delete_part_of_core_memory("challenges");
}

void Core::parse_input(const char* input, Tokens& t) {
    int len = strlen(input) + 1, temp_str_index = 0, number_of_tokens = t.get_number_of_tokens(input);
    char temp_str[101];

    t.tokens = new char* [number_of_tokens];
    t.size_of_token = new unsigned[number_of_tokens];
    
    for (int i = 0; i < len; i++)
    {
        if (input[i] == ' ' || input[i] == '\0') {
            temp_str[temp_str_index] = '\0';
            t.size_of_token[t.number_of_tokens] = temp_str_index;
            temp_str_index = 0;
            
            t.tokens[t.number_of_tokens] = new char[strlen(temp_str) + 1];;
            strcpy_s(t.tokens[t.number_of_tokens++] , strlen(temp_str) + 1 , temp_str);
        }
        else if (input[i] != ' ') {
            temp_str[temp_str_index++] = input[i];
        }
    }
}

void Core::get_profile_info(const Tokens& t) const{
    unsigned curr = 1;
    for (unsigned i = 0; i < this->users_size; i++)
    {
        if (strcmp(t.tokens[1], this->users[i]->get_name()) == 0) {
            std::cout << curr++ << ") ";
            this->users[i]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void Core::challenge(const Tokens& t) {
    if (!is_valid_challenge(t)) {
        std::cout << "Not a valid challenge!\n";
        return;
    }
    int challenge_index = this->get_challenge_index(t.tokens[2]);
    Challenge* ch = nullptr;
    if (challenge_index == -1) {
        ch = new Challenge(t.tokens[2]);
        
        this->add_challenge_to_core(ch);

        for (unsigned i = 3; i < t.number_of_tokens; i++)
        {
            if (this->has_more_than_one_user_with_name(t.tokens[i])) {
                std::cout << "The name " << t.tokens[i] << " is connected to more than one account.\nPlease specify which one you want to challenge. (Type \"all\" to challenge all the users, including the challenger)\n";
                this->print_users_by_given_name(t.tokens[i]);
                char temp[101];
                std::cin.getline(temp, 101);
                if (strcmp(temp, "all") == 0) {
                    for (unsigned k = 0; k < this->users_size; k++)
                    {
                        if (strcmp(this->users[k]->get_name(), t.tokens[i]) == 0) {
                            if (!this->users[k]->has_challenge(ch->get_challenge_name())) {
                                this->users[k]->add_challenge(ch);
                                ch->update_status();
                                std::cout << "Challenge added!\n";
                            }
                            else {
                                std::cout << "User " << this->users[k]->get_name() << "-" << this->users[k]->get_unique_id() << " already has challenge\nnThe challenge was not added";
                            }
                        }
                    }
                }
                else {
                    bool found_user = false;
                    for (unsigned j = 0; j < this->users_size; j++)
                    {
                        if (this->users[j]->get_unique_id() == std::stoul(temp)) {
                            if (!this->users[j]->has_challenge(ch->get_challenge_name())) {
                                this->users[j]->add_challenge(ch);
                                ch->update_status();
                                std::cout << "Challenge added!\n";
                                found_user = true;
                            }
                            else {
                                std::cout << "User " << this->users[j]->get_name() << " already has challenge\nnThe challenge was not added";
                            }
                        }
                    }
                    if (!found_user) {
                        std::cout << "Invalid ID. No challenge added.\n";
                    }
                }
            }
            else
            {
                unsigned user_index = this->get_user_index(t.tokens[i]);
                if (!this->users[user_index]->has_challenge(ch->get_challenge_name())) {
                    this->users[user_index]->add_challenge(ch);
                    ch->update_status();
                    std::cout << "Challenge added!\n";
                }
                else {
                    std::cout << "User " << this->users[user_index]->get_name() << " already has challenge\nnThe challenge was not added";
                }
            }
        }
    }
    else {
        ch = this->known_challenges[this->get_challenge_index(t.tokens[2])];
        for (unsigned i = 3; i < t.number_of_tokens; i++)
        {
            unsigned user_index = this->get_user_index(t.tokens[i]);
            if (!this->users[user_index]->has_challenge(ch->get_challenge_name())) {
                this->users[user_index]->add_challenge(ch);
                ch->update_status();
                std::cout << "Challenge added!\n";
            }
            else {
                std::cout << "User "<< this->users[user_index]->get_name() <<  " already has challenge\nnThe challenge was not added";
            }
        }
    }
}

void Core::register_user(Tokens& t) {
    User* a = nullptr;
    //incase the registration is not full (there is no email or no age)
    if (t.number_of_tokens == 4) {
        a = new User(t.tokens[1], atoi(t.tokens[2]), t.tokens[3]);
    }
    else if (t.number_of_tokens == 3) {
        if (atoi(t.tokens[2]) == 0) {
            if (atoi(t.tokens[2]) > 90 && atoi(t.tokens[2]) < 0) {
                std::cout << "Invalid age.\n";
            }
            a = new User(t.tokens[1], t.tokens[2]);
        }
        else {
            a = new User(t.tokens[1], atoi(t.tokens[2]));
        }
    }
    else if (t.number_of_tokens == 2) {
        a = new User(t.tokens[1]);
    }
    if (a != nullptr) {
        this->add_user(a);
        std::cout << "User registered!\n";
    }
    else {
        std::cout << "Whoops. Something bad happened. User not registered\n";
    }
}

void Core::finish_challenge(const Tokens& t) {
    bool found_user = false;
    int challenge_index = this->get_challenge_index(t.tokens[1]);
    if (challenge_index == -1) {
        std::cout << "No such challenge found.\n"; return;
    }
    for (unsigned i = 0; i < this->users_size && !found_user; i++)
    {
        if (std::stoul(t.tokens[2]) == this->users[i]->get_unique_id()) {

            if (this->users[i]->has_challenge(t.tokens[1])) {
                this->users[i]->
                    remove_challenge_from_user(this->known_challenges[challenge_index]);
                found_user = true;
            }
            else {
                std::cout << "User has no such challenge.\n"; return;
            }
        }
    }
    if (!found_user) {
        std::cout << "The given id isn’t valid. The user with this id do not exist.\n"; return;
    }
    this->known_challenges[challenge_index]->update_rating(atof(t.tokens[3]));
    std::cout << "Well done! May the challenge be with you!\n";
    

}

void Core::list_challenge(const Tokens& t) {
    std::cout << "Tag" << std::setw(30) << "Status" << std::setw(14) << "Rating" << std::setw(14) << "Total" << std::setw(15) << "Done\n";
    if (strcmp(t.tokens[1], "newest") == 0) {
        std::cout << "\tPrints the challenges by newest added\n";
        for (unsigned i = 0; i < this->challenges_size; i++)
        {
            this->known_challenges[i]->print_ch();
        }
    }else if (strcmp(t.tokens[1], "oldest") == 0) {
        std::cout << "\tPrints the challenges by oldest added\n";
        for (int i = this->challenges_size - 1; i >= 0; i--)
        {
            this->known_challenges[i]->print_ch();
        }
    }else if (strcmp(t.tokens[1], "most_popular") == 0) {
        std::cout << "\tPrints the challenges by which one is the most popular\n";
        Challenge** sorted_challenge_list = new Challenge * [this->challenges_size];
        for (unsigned i = 0; i < this->challenges_size; i++)
        {
            sorted_challenge_list[i] = this->known_challenges[i];
        }
        std::sort(sorted_challenge_list, sorted_challenge_list + this->challenges_size - 1,
            [](Challenge* a, Challenge* b) {
                return a->get_times_called() >= b->get_times_called();
            });
        for (unsigned i = 0; i < this->challenges_size; i++)
        {
            sorted_challenge_list[i]->print_ch();
        }
        delete[] sorted_challenge_list;
    }
}

void Core::load_file(const Tokens& t)
{

    std::ifstream o_file(t.tokens[1]);
    if (!o_file)
    {
        std::cout << "bad file\n"; return;
    }
    char temp[101];
    if (strcmp(t.tokens[1] + t.size_of_token[1] - 3, "txt") == 0) {
        User* a = nullptr;
        while (o_file.getline(temp, 101))
        {
            Tokens file_input;
            this->parse_input(temp, file_input);
            if (file_input.number_of_tokens == 3) {
                a = new User(file_input.tokens[0], atoi(file_input.tokens[1]), file_input.tokens[2]);
            }
            else if (file_input.number_of_tokens == 2) {
                if (atoi(file_input.tokens[1]) == 0) {
                    a = new User(file_input.tokens[0], file_input.tokens[1]);
                }
                else {
                    a = new User(file_input.tokens[0], atoi(file_input.tokens[1]));
                }
            }
            else if (file_input.number_of_tokens == 1) {
                a = new User(file_input.tokens[0]);
            }
            this->add_user(a);
            file_input.delete_memory();
        }
        std::cout << "File with users loaded\n";
    }
    else if (strcmp(t.tokens[1] + t.size_of_token[1] - 3, "bin") == 0) {
        std::cout << "in bin file\n";
        //pazi se informaciqta po tozi nachin - name_len, name , times_called, times_finished, rating. Ne beshe kazano kak trqbva da se podava
        while (o_file)
        {
            unsigned len, times_called, times_finished;
            double rating;
            o_file.read((char*)&len, sizeof(len));
            char* name = new char[len + 1];
            o_file.read(name, len);
            name[len] = '\0';
            o_file.read((char*)&times_called, sizeof(times_called));
            o_file.read((char*)&times_finished, sizeof(times_finished));
            o_file.read((char*)&rating, sizeof(rating));
            Challenge* ch = new Challenge(name, times_called, times_finished, rating);
            this->add_challenge_to_core(ch);
        }
        std::cout << "File with challenges loaded\n";
    }
    else {
        std::cout << "Unrecognizable file.\nShould be with the .txt extention to add users, or .bin extention to add challenges\n";
    }
    o_file.close();
}

void Core::print_users_by_given_name(const char* name) const
{
    unsigned curr = 1;
    for (unsigned i = 0; i < this->users_size; i++)
    {
        if (strcmp(this->users[i]->get_name(), name) == 0) {
            std::cout << curr++ << ") ";
            this->users[i]->print();
            std::cout << std::endl;
        }
    }
}


void Core::print_info_for_core() const {
    std::cout << "The program has these commands:\n -profile_info\n -register\n -finish\n -list_by\n -load\n -challenge\n -print_all_users\n";
}

void Core::print_all_users()const {
    for (unsigned i = 0; i < this->users_size; i++)
    {
        this->users[i]->print();
    }
}

bool Core::has_more_than_one_user_with_name(const char* name) const
{
    int occur = 0;
    for (unsigned i = 0; i < this->users_size; i++)
    {
        if (strcmp(this->users[i]->get_name(), name) == 0) {
            ++occur;
        }
        if(occur >= 2){
            return true;
        }
    }
    return false;
}



#endif //!CORE_CPP