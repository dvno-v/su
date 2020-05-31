#ifndef SALAD_CPP

#define SALAD_CPP

#include "Salad.h"
#include <iostream>

Salad::Salad(std::string _name, double _price, int _grams, int _portions , int _grams_per_portions, int _products, bool _ovkusena)
    :Food(_name, "Salad", _price, _grams, _portions, _grams_per_portions)
{
    this->ovkusena = _ovkusena;
    this->number_of_products = _products;
}

Salad::~Salad(){}


void Salad::print() const{
    std::cout << this->name << "<->" << this->price_per_portion << "  salad\n";
}

#endif