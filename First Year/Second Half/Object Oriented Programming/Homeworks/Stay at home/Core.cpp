#ifndef CORE_CPP

#define CORE_CPP

#include "Core.h"
#include <cstring>
#include <iostream>
#include <cstdlib>


//Tokens logic
void Tokens::delete_memory() {
    for (unsigned i = 0; i < this->number_of_tokens; i++)
    {
        delete[] this->tokens[i];
    }
    delete[] this->tokens;
    delete[] this->size_of_token;
}

unsigned Tokens::get_number_of_tokens(const char* input)
{
    int length = strlen(input) + 1, number_of_tokens = 0;
    for (unsigned i = 0; i < length; i++)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            ++number_of_tokens;
        }
    }
    return number_of_tokens;
}

void Tokens::print() const {
    for (unsigned i = 0; i < this->number_of_tokens; i++)
    {
        for (unsigned k = 0; k < this->size_of_token[i]; k++)
        {
            std::cout << this->tokens[i][k];
        }
        std::cout << '\n';
    }
}
//End of tokens logic

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

Core::Core() {
    this->users = nullptr;
    this->users_size = 0;
    this->known_challenges = nullptr;
    this->challenges_size = 0;
}
Core::~Core() {
    
}

void Core::parse_input(const char* input, Tokens& t) {
    int len = strlen(input) + 1, temp_str_index = 0, number_of_tokens = t.get_number_of_tokens(input);
    char temp_str[101];

    t.tokens = new char* [number_of_tokens];
    t.size_of_token = new unsigned[number_of_tokens];
    
    for (int i = 0; i < len; i++)
    {
        if (input[i] == ' ' || input[i] == '\0') {
            //std::cout << temp_str_index << '\n';
            temp_str[temp_str_index] = '\0';
            t.size_of_token[t.number_of_tokens] = temp_str_index;
            temp_str_index = 0;
            //std::cout << temp_str << '\n';
            
            t.tokens[t.number_of_tokens] = new char[strlen(temp_str) + 1];;
            strcpy_s(t.tokens[t.number_of_tokens++] , strlen(temp_str) + 1 , temp_str);
        }
        else if (input[i] != ' ') {
            //std::cout << "in here" << '\n';
            temp_str[temp_str_index++] = input[i];
        }
    }
}

void Core::register_user(Tokens& t) {
    //incase the registration is not full (there is no email or no age)
    if (t.number_of_tokens == 4) {
        User a = new User(t.tokens[1], atoi(t.tokens[2]), t.tokens[3]);
    }
    else if (t.number_of_tokens == 3) {
        if (atoi(t.tokens[2]) == 0) {
            User
        }
    }
}

void Core::print_info_for_core() const {
    std::cout << "The program has these commands:\n -profile_info\n -register\n -finish\n -list_by\n -load\n -challenge\n";
}




#endif //!CORE_CPP