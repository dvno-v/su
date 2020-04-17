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
    Challenge* challenges;

    void del_memory(char const *);
    char* copy_memory(char const *);

public:
    User(const char*, unsigned, const char*);
    User(const char*, unsigned);
    User(const char*, const char*);
    User(const char*);
    ~User();

    unsigned get_unique_id() const;

    bool add_challenge(const Challenge&);
    bool remove_challenge(const Challenge&);
    
    void print() const;
};


#endif //! USER_H