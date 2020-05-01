#ifndef STRING_CPP

#define STRING_CPP

#include "String.hpp"
#include <cstring>
#include <iostream>

char * String::copy_memory(const char* source){
    char* temp = new char[strlen(source) + 1];
    strcpy(temp, source);

    return temp;
}

void String::erase_mem(){
    delete[] this->data;
}

void String::enlarge_str(){
    this->capacity *= 2;
    char* temp = new char[this->capacity];
    strcpy(temp, this->data);

    temp[strlen(this->data)] = '\0';
    this->erase_mem();

    this->data = temp;
}


String::String()
{
    this->data = (char*)"";
    this->capacity = 1;
}

String::String(const char* _data){
    this->data = copy_memory(_data);
    this->capacity = (strlen(_data) + 1) * 2;
}

String::String(const String& _other){
    this->data = copy_memory(_other.data);
    this->capacity = _other.capacity;
}

String::~String()
{
    this->erase_mem();
}

String& String::operator=(const String& _other){
    if(&_other != this){ 
        this->erase_mem();
        this->data = copy_memory(_other.data);
        this->capacity = _other.capacity;
    }
    return *this;
}

unsigned String::get_length() const {
    return strlen(this->data);
}

unsigned String::get_capacity() const {
    return this->capacity;
}

String& String::append(const char* _to_append){
    unsigned desired_length = this->get_length() + strlen(_to_append) + 1;
    while (desired_length > this->get_capacity())
    {
        this->enlarge_str();
        // std::cout << this->data << '\n';
    }
    int count = strlen(_to_append), old_lenght = this->get_length();
    for (unsigned i = 0; i < count ; i++)
    {
        this->data[old_lenght + i] = _to_append[i];
        // std::cout << this->data << '\n';
    }
    this->data[desired_length - 1] = '\0';

    return *this;
    
}
String& String::append(const String& _other){
    this->append(_other.data);
    return *this;
}


bool String::empty() const {
    return this->capacity == 1;
}

void String::erase(){
    String temp;
    *this = temp;
    temp.~String();
}

std::ostream& operator<<(std::ostream& out , const String& s){
    out << s.data << '\n';
    return out;
}


#endif //!STRING_CPP