#ifndef PIZZA_CPP

#define PIZZA_CPP

#include "Pizza.h"
#include <iostream>

Pizza::Pizza(std::string _name, std::string _type, double _price, int _grams, int _portions , int _grams_per_portions)
    :Food(_name, "Pizza", _price, _grams, _portions, _grams_per_portions)
{
    this -> type_of_pizza = _type;
}

Pizza::~Pizza(){}

void Pizza::print() const{
    std::cout << this->name << "<->" << this->price_per_portion << "  pizza\n";
}


#endif