#ifndef USER_CPP

#define USER_CPP

#include <iostream>
#include <cstring>
#include <cassert>
#include "User.h"

const unsigned MAX_EMAIL_LENGTH = 101;
const unsigned MAX_AGE = 90;
const unsigned MAX_NAME_LENGTH = 101;
const unsigned NO_AGE = -404;


char* User::copy_memory(char const * source){
    char* temp = new char[strlen(source) + 1];
    strcpy(temp, source);
    return temp;
}

void User::del_memory(char const * to_delete){
    if(strcmp(to_delete, "email") == 0){
        // std::cout << "deleted email\n"; 
        delete[] this->email;
    }
    if(strcmp(to_delete, "name") == 0){
        // std::cout << "deleted name\n"; 
        delete[] this->name;
    }
    if(strcmp(to_delete, "challenges") == 0){
        // std::cout << "deleted challenges\n"; 
        delete[] this->challenges;
    }
 }

User::User(const char* _name , unsigned _age, const char* _email){
    assert(strlen(_name) < MAX_NAME_LENGTH);
    assert(strlen(_email) < MAX_EMAIL_LENGTH);
    assert(_age <= MAX_AGE && _age >=1);

    this->unique_id = reinterpret_cast<unsigned long>(this);
    this->age = _age;
    this->name = copy_memory(_name);
    this->email = copy_memory(_email);
    this->number_of_challenges = 0;
    this->challenges = nullptr;
}

User::User(const char* _name , unsigned _age){
    assert(strlen(_name) < MAX_NAME_LENGTH);
    assert(_age <= MAX_AGE && _age >=1);

    this->unique_id = reinterpret_cast<unsigned long>(this);
    this->age = _age;
    this->name = copy_memory(_name);
    this->email = copy_memory("Unknown");
    this->challenges = nullptr;
    this->number_of_challenges = 0;
}

User::User(const char* _name, const char* _email){
    assert(strlen(_name) < MAX_NAME_LENGTH);
    assert(strlen(_email) < MAX_EMAIL_LENGTH);

    this->unique_id = reinterpret_cast<unsigned long>(this);
    this->age = NO_AGE;
    this->name = copy_memory(_name);
    this->email = copy_memory(_email);
    this->number_of_challenges = 0;
    this->challenges = nullptr;
}

User::User(const char* _name){
    assert(strlen(_name) < MAX_NAME_LENGTH);

    this->unique_id = reinterpret_cast<unsigned long>(this);
    this->age = NO_AGE;
    this->name = copy_memory(_name);
    this->email = copy_memory("Unknown");
    this->number_of_challenges = 0;
    this->challenges = nullptr;
}


User::~User(){
    this->del_memory("name");
    this->del_memory("email");
    this->del_memory("challenges");
}

unsigned User::get_unique_id() const{
    return this->unique_id;
}

// bool User::add_challenge(const char * challenge_name ){
    
// }




void User::print() const{
    // std::cout << this->name << "   " << this->age << "   "<< this->email << '\n';
    std::cout << this->unique_id << '\n';
}

#endif // !USER_CPP