#ifndef USER_CPP

#define USER_CPP

#include <iostream>
#include <cstring>
#include <cassert>
#include "User.h"

const unsigned MAX_EMAIL_LENGTH = 100;
const unsigned MAX_AGE = 90;
const unsigned MAX_NAME_LENGTH = 100;


char* User::copy_memory(char const * source){
    char* temp = new char[strlen(source) + 1];
    strcpy(temp, source);
    return temp;
}

void User::del_memory(){
    delete[] this->email;
    delete[] this->name;
}
User::User(const char* _name , unsigned _age, const char* _email){
    this->unique_id = reinterpret_cast<unsigned>(this);
    this->age = _age;
    this->name = copy_memory(_name);
    this->email = copy_memory(_email);
}
User::User(const char* _name , unsigned _age){
    this->unique_id = reinterpret_cast<unsigned>(this);
    this->age = _age;
    this->name = copy_memory(_name);
    this->email = copy_memory("");
}

User::User(const char* _name, const char* _email){
    this->unique_id = reinterpret_cast<unsigned>(this);
    this->age = 0;
    this->name = copy_memory(_name);
    this->email = copy_memory(_email);
}
User::User(const char* _name){
    this->unique_id = reinterpret_cast<unsigned>(this);
    this->age = 0;
    this->name = copy_memory(_name);
    this->email = copy_memory("");
}


User::~User(){
    this->del_memory();
}

void User::print() const{
    std::cout << this->name << "   " << this->age << "   "<< this->email << '\n';
}

#endif // !USER_CPP