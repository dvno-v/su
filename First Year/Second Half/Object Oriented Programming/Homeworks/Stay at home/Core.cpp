#ifndef CORE_CPP

#define CORE_CPP

#include "Core.h"
#include <cstring>
#include <iostream>

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


void Core::parse_input(const char* input, Tokens& t) {
    int len = strlen(input) + 1, temp_str_index = 0, number_of_tokens = t.get_number_of_tokens(input);
    char temp_str[101];

    t.tokens = new char* [number_of_tokens];
    t.size_of_token = new unsigned[number_of_tokens];
    
    for (int i = 0; i < len; i++)
    {
        if (input[i] == ' ' || input[i] == '\0') {
            std::cout << temp_str_index << '\n';
            temp_str[temp_str_index] = '\0';
            t.size_of_token[t.number_of_tokens] = temp_str_index;
            temp_str_index = 0;
            std::cout << temp_str << '\n';
            
            t.tokens[t.number_of_tokens] = new char[strlen(temp_str) + 1];;
            strcpy_s(t.tokens[t.number_of_tokens++] , strlen(temp_str) + 1 , temp_str);
        }
        else if (input[i] != ' ') {
            std::cout << 'i' << '\n';
            temp_str[temp_str_index++] = input[i];
        }
    }
}



Core::Core() {

}
Core::~Core() {

}


#endif //!CORE_CPP