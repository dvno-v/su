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
    void print() const;
};

class Core
{
private:
     User** users;
     unsigned users_size;
     Challenge** known_challenges;
     unsigned challenges_size;

     void delete_part_of_core_memory(const char*);
public:
    Core();
    Core(User*);
    Core(Challenge**);
    Core(User*, Challenge**);
    ~Core();

    void register_user(Tokens&);
    void parse_input(const char*, Tokens&);
    void challenge(const Tokens&);
    void finish_challenge(const Tokens&);
    void get_profile_info(const Tokens&);
    void list_challenge(const Tokens&);
    void load_file(const Tokens&);
    void print_users_by_given_name(const char*) const;
    
    void print_info_for_core() const;

};

#endif //!CORE_H