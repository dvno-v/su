#ifndef USER_H

#define USER_H
#include "Challenge.h"

class User
{
private:
    unsigned unique_id;
    char* name;
    unsigned age;
    char* email;

    Challenge* challenges;

    void del_memory();
    char* copy_memory(char const *);

public:
    User(const char*, unsigned, const char*);
    User(const char*, unsigned);
    User(const char*, const char*);
    User(const char*);
    ~User();

    void print() const;
};


#endif //! USER_H