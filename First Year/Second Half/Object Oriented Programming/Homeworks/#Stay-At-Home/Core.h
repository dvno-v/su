#ifndef CORE_H

#define CORE_H

#include "User.cpp"
#include "Challenge.cpp"

struct Tokens
{
    char** tokens;
    unsigned number_of_tokens;
    unsigned* size_of_token;
    void delete_memory();
};

class Core
{
private:
    // User* users;
    // Challenge** known_challenges;
public:
    Core();
    // Core(User*);
    // Core(Challenge**);
    // Core(User*, Challenge**);
    ~Core();

    void parse_input(const char*, Tokens&);
};

#endif //!CORE_H