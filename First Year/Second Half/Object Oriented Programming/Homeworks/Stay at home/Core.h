#ifndef CORE_H

#define CORE_H

#include "User.h"
#include "Challenge.h"
#include "Tokens.h"

class Core
{
private:
     User** users;
     unsigned users_size;
     Challenge** known_challenges;
     unsigned challenges_size;

     void delete_part_of_core_memory(const char*);
     bool contains_challenge(const char*) const;
     bool is_valid_challenge(const Tokens&) const;
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
    void get_profile_info(const Tokens&) const;
    void list_challenge(const Tokens&);
    void load_file(const Tokens&);
    void print_users_by_given_name(const char*) const;
    
    void print_info_for_core() const;
    void print_all_users() const;

};

#endif //!CORE_H