#ifndef USER_CPP

#define USER_CPP

#include <iostream>
#include <cstring>
#include <cassert>
#include "User.h"

const unsigned MAX_EMAIL_LENGTH = 101;
const unsigned MAX_AGE = 90;
const unsigned MAX_NAME_LENGTH = 101;


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
   
}
User::User(const char* _name , unsigned _age, const char* _email){
    assert(strlen(_name) < MAX_NAME_LENGTH);
    assert(strlen(_email) < MAX_EMAIL_LENGTH);
    assert(_age <= MAX_AGE);
    this->unique_id = reinterpret_cast<unsigned>(this);
    this->age = _age;
    this->name = copy_memory(_name);
    this->email = copy_memory(_email);
}
User::User(const char* _name , unsigned _age){
    assert(strlen(_name) < MAX_NAME_LENGTH);
    assert(_age <= MAX_AGE);
    this->unique_id = reinterpret_cast<unsigned>(this);
    this->age = _age;
    this->name = copy_memory(_name);
    this->email = copy_memory("");
}

User::User(const char* _name, const char* _email){
    assert(strlen(_name) < MAX_NAME_LENGTH);
    assert(strlen(_email) < MAX_EMAIL_LENGTH);
    this->unique_id = reinterpret_cast<unsigned>(this);
    this->age = 0;
    this->name = copy_memory(_name);
    this->email = copy_memory(_email);
}
User::User(const char* _name){
    assert(strlen(_name) < MAX_NAME_LENGTH);
    this->unique_id = reinterpret_cast<unsigned>(this);
    this->age = 0;
    this->name = copy_memory(_name);
    this->email = copy_memory("");
}


User::~User(){
    this->del_memory("name");
    this->del_memory("email");
}

void User::print() const{
    // std::cout << this->name << "   " << this->age << "   "<< this->email << '\n';
    std::cout << this->unique_id << '\n';
}

#endif // !USER_CPP