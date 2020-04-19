#ifndef CORE_H

#define CORE_H

#include "User.h"
#include "Challenge.h"

struct Tokens
{
    char** tokens{nullptr};
    unsigned number_of_tokens{0};
    unsigned* size_of_token{nullptr};
    void delete_memory();
    unsigned get_number_of_tokens(const char *);
    void print();
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
    void challenge(Tokens&);
    void get_profile_info(Tokens&);
    void list_challenge(Tokens&);
};

#endif //!CORE_H