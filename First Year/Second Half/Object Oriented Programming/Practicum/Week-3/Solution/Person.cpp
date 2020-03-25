#ifndef __PERSON_CPP

#define __PERSON_CPP

#include <cstring>
#include <iostream>
#include "Person.h"


char* Person::copy_dynamic(char* source){
    char* to = new char[strlen(source) + 1];
    strcpy(to, source);
    return to;
}
void Person::delete_dynamic(){
    delete[] this->name;
}

void Person::copy_person(const Person& source){
    this->name = copy_dynamic(source.name);
    this->age = source.age;
    this->has_licence = source.has_licence && age >= 18;

}

Person::Person() : name(nullptr)
{
    this->age = 0;
    this->has_licence = false;
}

Person::Person(const Person& a)
{
    this->copy_person(a);
}

Person::Person(char* __name, const int& __age, const bool& __has_licence): name(nullptr)
{
    this->name = copy_dynamic(__name);
    this->age = __age;
    this->has_licence = __has_licence && age >= 18;
}

Person::~Person()
{
    this->delete_dynamic();
}

Person& Person::operator=(const Person&other){
    this->copy_person(other);
    return *this;
}

bool Person::operator==(const Person& other){
    bool names_eq = strcmp(name, other.name) == 0;
    return names_eq && other.age == age && has_licence == other.has_licence;
}

void Person::set_name(char*a){
    this->name = this->copy_dynamic(a);
}

void Person::set_age(const int& a){
    this->age = a;
}

void Person::set_licence(const bool& a){
    this->has_licence = this->has_licence && this->age >= 18;
}

char* Person::get_name() const{
    return this->name;
}

int Person::get_age() const{
    return this->age;
}

bool Person::get_if_licence() const{
    return this->has_licence;
}

void Person::print_person() const{
    std::cout << this->name << "  " << this->age << "  "<< std::boolalpha << this->has_licence << '\n';
}


#endif // !__PERSON_CPP