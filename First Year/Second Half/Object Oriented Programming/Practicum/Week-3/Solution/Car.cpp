#ifndef __CAR_CPP

#define __CAR_CPP

#include "Car.h"

char* Car::copy_dynamic(char* source){
    char* to = new char[strlen(source) + 1];
    strcpy(to, source);
    return to;
}
void Car::delete_dynamic(){
    delete[] this->brand;
    delete[] this->licence_plate;
    delete[] this->colour;
}

void Car::copy_car(const Car& source){
    this->brand = copy_dynamic(source.brand);
    this->licence_plate = copy_dynamic(source.licence_plate);
    this->colour = copy_dynamic(source.colour);
    this->owner = source.owner;
}

Car::Car(): brand(nullptr), licence_plate(nullptr), colour(nullptr), owner(Person()){}

Car::Car(const Car& other){
    this->copy_car(other);
}

Car::Car(char* __brand, char* __licence_plate, char* __colour, const Person& __owner){
    this->brand = copy_dynamic(__brand);
    this->licence_plate = copy_dynamic(__licence_plate);
    this->colour = copy_dynamic(__colour);
    this->owner = __owner;
}

Car::~Car(){
    this->delete_dynamic();
}

Car& Car::operator=(const Car&a){
    this->copy_car(a);
    return *this;
}

bool Car::operator==(const Car&a){
    return strcmp(brand, a.brand) == 0 
            && strcmp(colour, a.colour) == 0
            && strcmp(licence_plate, a.licence_plate) == 0
            && (owner == a.owner) ;
}

void Car::set_brand(char* __brand){
    this->brand = copy_dynamic(__brand); 
}

void Car::set_licence_plate(char* __licence){
    this->licence_plate = copy_dynamic(__licence); 
}

void Car::set_colour(char* __colour){
    this->colour = copy_dynamic(__colour); 
}

void Car::set_owner(const Person& __owner){
    this->owner = __owner; 
}

char* Car::get_brand() const{
    return this->brand;
}

char* Car::get_licence_plate() const{
    return this->licence_plate;
}

char* Car::get_colour() const{
    return this->colour;
}

Person Car::get_owner() const{
    return owner;
}

void Car::print_car() const{
    std::cout << this->brand << " " << this->colour << " " << '\n';
    owner.print_person();  
}

bool Car::if_owner_can_drive()const{
    return this->owner.get_if_licence();
}

#endif // !__CAR_CPP