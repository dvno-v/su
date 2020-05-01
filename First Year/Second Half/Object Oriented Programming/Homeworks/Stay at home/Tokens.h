#ifndef TOKENS_H

#define TOKENS_H


struct Tokens
{
    char** tokens{ nullptr };
    unsigned number_of_tokens{ 0 };
    unsigned* size_of_token{ nullptr };
    void delete_memory();
    unsigned get_number_of_tokens(const char*);
    void print() const;
};


#endif // !TOKENS_H
