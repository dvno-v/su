#ifndef CHALLENGE_CPP

#define CHALLENGE_CPP

#include <iostream>
#include <cstring>
#include "Challenge.h"

Challenge::Challenge(/* args */)
{
}

Challenge::~Challenge()
{
}

char* Challenge::copy_challenge_memory(char const* source) {
    char* temp = new char[strlen(source) + 1];
    strcpy_s(temp, strlen(source) + 1, source);
    return temp;
}

void Challenge::del_challenge_memory(char const* to_delete) {
    if (strcmp(to_delete, "status") == 0) {
        // std::cout << "deleted email\n"; 
        delete[] this->status;
    }
    if (strcmp(to_delete, "name") == 0) {
        // std::cout << "deleted name\n"; 
        delete[] this->name;
    }
}

#endif //! CHALLENGE_CPP