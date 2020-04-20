#ifndef USER_H

#define USER_H

#include "Challenge.h"

class User
{
private:
    unsigned long unique_id;
    char* name;
    unsigned age;
    char* email;
    Challenge** challenges;
    unsigned number_of_challenges;

    void del_user_memory(char const*);
    char* copy_user_memory(char const*);
    void init_challenge_list();
public:
    User(const char*, unsigned, const char*);
    User(const char*, unsigned);
    User(const char*, const char*);
    User(const char*);
    User(const User&);
    ~User();

    const unsigned get_unique_id() const;
    const char* get_name() const;

    void add_challenge(Challenge*);
    void remove_challenge_from_user(Challenge*);
    bool has_challenge(const char*) const;

    void print() const;
    void print_user_challenges() const;
};


#endif //! USER_H