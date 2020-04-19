#ifndef TOKENS_CPP

#define TOKENS_CPP

#include "Tokens.h"
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

#endif // !TOKENS_CPP

