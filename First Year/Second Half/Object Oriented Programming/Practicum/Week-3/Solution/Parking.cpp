#ifndef __PARKING_CPP

#define __PARKING_CPP

#include "Parking.h"
#include <cmath>
#include <assert.h>

char* Parking::copy_dynamic(char* source){
    char* to = new char[strlen(source) + 1];
    strcpy(to, source);
    return to;
}

void Parking::delete_parking(){
    delete[] this->fname;
    delete[] this->cars;
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

Parking::Parking(char* __fname, const Person& __owner, Car* __cars, size_t __car_count, size_t __capacity){
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

Parking& Parking::add_car(const Car& to_add){
    assert((this->cars_count + 1) < this->capacity);
    Car* new_park_arr = new Car[this->cars_count + 1];
    for (size_t i = 0; i < this->cars_count; i++)
    {
        new_park_arr[i] = this->cars[i];
    }
    new_park_arr[this->cars_count] = to_add;
    ++(this->cars_count);
    delete[] this->cars;

    this->cars = new_park_arr;
    return *this;
}

Parking& Parking::del_car(const int& index){
    for (size_t i = index; i < this->cars_count - 1; i++)
    {
        this->cars[i] = this->cars[i + 1];
    }
    --(this->cars_count);
    return *this;
}

Person Parking::get_owner(char * licence){
    for (size_t i = 0; i < this->cars_count; i++)
    {
        if(strcmp(licence, this->cars[i].get_licence_plate()) == 0){
            return this->cars[i].get_owner();
        }
    }
    return Person();
}

void Parking::print_all_owned_by_owner(const Person& owner){
    for (size_t i = 0; i < this->cars_count; i++)
    {
        if((this->cars[i]).get_owner() == owner){
            this->cars[i].print_car();
        }
    }
}

void Parking::print_all(){
    for (size_t i = 0; i < this->cars_count; i++)
    {
        this->cars[i].print_car();
    }
    
}

//TO-DO: getters and setters for class Parking(i was lazy)

#endif