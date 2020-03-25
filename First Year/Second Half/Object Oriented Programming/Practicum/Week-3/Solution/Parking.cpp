#ifndef __PARKING_CPP

#define __PARKING_CPP

#include "Parking.h"
#include <cmath>

char* Parking::copy_dynamic(char* source){
    char* to = new char[strlen(source) + 1];
    strcpy(to, source);
    return to;
}

void Parking::delete_parking(){
    delete[] this->fname;
}

void Parking::copy_park(const Parking& a){
    this->fname = copy_dynamic(a.fname);
    this->owner = a.owner;
    this->cars = new Car[a.capacity];
    for (size_t i = 0; i < a.cars_count; i++)
    {
        this->cars[i] = a.cars[i];
    }
    this->cars_count = a.cars_count;
    this->capacity = a.capacity;
}

Parking::Parking(): fname(nullptr), owner(Person()), cars(nullptr), cars_count(0){}

Parking::Parking(const Parking& a){
    this->copy_park(a);
}

Parking::Parking(char* __fname, const Person& __owner, const Car*& __cars, size_t __car_count, size_t __capacity){
    this->fname = copy_dynamic(__fname);
    this->owner = __owner;
    this->cars = new Car[__capacity];
    for (size_t i = 0; i < __car_count; i++)
    {
        this->cars[i] = __cars[i];
    }
    this->cars_count = __car_count;
    this->capacity = __capacity;
}

Parking::~Parking(){
    this->delete_parking();
}


#endif