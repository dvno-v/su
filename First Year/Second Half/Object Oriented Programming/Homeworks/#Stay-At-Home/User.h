#ifndef USER_H

#define USER_H

#include "Challenge.cpp"

class User
{
private:
    unsigned long unique_id;
    char* name;
    unsigned age;
    char* email;
    Challenge** challenges;
    unsigned number_of_challenges;

    void del_memory(char const *);
    char* copy_memory(char const *);
    void init_challenge_list();
public:
    User(const char*, unsigned, const char*);
    User(const char*, unsigned);
    User(const char*, const char*);
    User(const char*);
    ~User();

    unsigned get_unique_id() const;

    bool add_challenge(char const *);
    bool remove_challenge(char const *);
    
    void print() const;
};


#endif //! USER_H