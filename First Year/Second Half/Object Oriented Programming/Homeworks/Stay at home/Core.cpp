 #ifndef CORE_CPP

#define CORE_CPP

#include "Core.h"
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>


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

bool Core::is_valid_challenge(const Tokens& t) const
{
    if(strlen(t.tokens[2]) > MAX_CHALLENGE_NAME_LENGTH || *(t.tokens[2]) != '#')
        return false;
    // tokens[0] - 'challenge' token[1] - challenger tokens[2] - challenge, others -> the challenged 
    for (unsigned i = 1; i < t.number_of_tokens; i++)
    {
        if (i == 2) 
            continue;

        if (this->get_user_index(t.tokens[i]) == -1)
            return false;
    }
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
    for (unsigned i = 0; i < this->users_size; i++)
    {
        if (strcmp(t.tokens[1], this->users[i]->get_name()) == 0) {
            std::cout << i + 1 << ") ";
            this->users[i]->print();
        }
    }
}

void Core::challenge(const Tokens& t) {
    if (!is_valid_challenge(t)) {
        std::cout << "Not a valid challenge!!!!!!\nObesi se be drishlio\n";
        return;
    }
    int challenge_index = this->get_challenge_index(t.tokens[2]);
    Challenge* ch = nullptr;
    if (challenge_index == -1) {
        ch = new Challenge(t.tokens[2]);
        
        this->add_challenge_to_core(ch);

        for (unsigned i = 3; i < t.number_of_tokens; i++)
        {
            this->users[this->get_user_index(t.tokens[i])]->add_challenge(ch);
        }
    }
    else {
        ch = this->known_challenges[this->get_challenge_index(t.tokens[2])];
        for (unsigned i = 3; i < t.number_of_tokens; i++)
        {
            this->users[this->get_user_index(t.tokens[i])]->add_challenge(ch);
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
            a = new User(t.tokens[1], t.tokens[2]);
        }
        else {
            a = new User(t.tokens[1], atoi(t.tokens[2]));
        }
    }
    else if (t.number_of_tokens == 2) {
        a = new User(t.tokens[1]);
    }
    User** temp = new User * [this->users_size + 1];
    for (size_t i = 0; i < this->users_size; i++)
    {
        temp[i] = this->users[i];
    }
    this->delete_part_of_core_memory("users");
    temp[this->users_size++] = a;
    this->users = temp;
}

void Core::finish_challenge(const Tokens& t) {
    bool found_user = false;
    unsigned challenge_index = this->get_challenge_index(t.tokens[1]);
    for (unsigned i = 0; i < this->users_size; i++)
    {
        if (std::stoul(t.tokens[2]) == this->users[i]->get_unique_id()) {
            this->users[i]->
                remove_challenge_from_user(this->known_challenges[challenge_index]);
            found_user = true;
        }
    }
    if (!found_user) {
        std::cout << "User not found\n"; return;
    }
    this->known_challenges[challenge_index]->update_rating(atof(t.tokens[3]));
    this->known_challenges[challenge_index]->update_status();

}

void Core::list_challenge(const Tokens& t) {
    for (unsigned i = 0; i < this->challenges_size; i++)
    {
        this->known_challenges[i]->print_ch();
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



#endif //!CORE_CPP