#ifndef FOOD_CPP
#define FOOD_CPP

#include "Food.h"
#include <iostream>

Food::Food(std::string _name, std::string _category, double _price_per_portion, int _grams, int _portions, int _grams_per_portion)
{
    this->name = _name;
    this->category = _category;
    this->price_per_portion = _price_per_portion;
    this->grams = _grams;
    this->available_portions = _portions;
    this->grams_per_portion = _grams_per_portion;
    this->set_id();
}

Food::~Food(){}

int Food::get_id() const{
    return this->id;
}

double Food::get_price() const{
    return this->price_per_portion;
}

void Food::set_id(){
    this->id = reinterpret_cast<int>(this);
}

void Food::consume(){
    if(this->available_portions > 0){
        this->grams -= this->grams_per_portion;
        --this->available_portions;
    }
}

std::string Food::get_category() const {
    return this->category;
}

void Food::print() const{
    std::cout << this->name << "<->" << this->price_per_portion << "  food\n";
}

#endif // FOOD_CPP