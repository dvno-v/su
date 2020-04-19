#ifndef CORE_CPP

#define CORE_CPP

#include "Core.h"
#include <cstring>
#include <iostream>

void Tokens::delete_memory(){
    for (unsigned i = 0; i < this->number_of_tokens; i++)
    {
        delete[] this->tokens[i];
    }
    delete[] this->tokens;
    delete[] this->size_of_token;
    
}

void Core::parse_input(const char* input, Tokens& t){
    int len = strlen(input), temp_str_index = 0;
    char temp_str[101];
    for (int i = 0; i < len + 1; i++)
    {
        if (input[i] == ' ' || input[i] == '\0'){
            temp_str[temp_str_index] = '\0';
            temp_str_index = 0;
            // std::cout << temp_str << '\n';
            char* add_to_token = new char[strlen(temp_str) + 1];
            strcpy(add_to_token, temp_str);
            t.tokens[t.number_of_tokens++] = add_to_token;
        }
        else if(input[i] != ' '){
            temp_str[temp_str_index++] = input[i];
        }
    }
}



Core::Core(){

}
Core::~Core(){

}


#endif //!CORE_CPP