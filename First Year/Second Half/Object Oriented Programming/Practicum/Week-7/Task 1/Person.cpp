#ifndef PERSON_CPP
#define PERSON_CPP


#include "Person.h"

Person::Person(): birth_date(Date()), name("default") {}

Person::Person(const Date& _date, std::string _name):
                birth_date(_date), 
                name(_name){}

Person::Person(const Person& _other){
    this->birth_date = _other.birth_date;
    this->name = _other.name;
}

Person& Person::operator=(const Person& _other){
    this->birth_date = _other.birth_date;
    this->name = _other.name;

    return *this;
}

Person::~Person(){
    
}

#endif /* end of include guard: PERSON_CPP */
