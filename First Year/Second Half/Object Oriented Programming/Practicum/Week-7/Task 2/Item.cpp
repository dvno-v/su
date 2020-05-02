#ifndef ITEM_CPP

#define ITEM_CPP

#include <cmath>
#include <iostream>
#include "Item.h"

const double EPS = 0.00001;

Item::Item(){
    this->name = "placeholder";
    this->price = 0.0;
}

Item::Item(const std::string& _name,const double& _price){
    this->name = _name;
    this->price = _price;
}
Item::Item(const Item& _other){
    this->name = _other.name;
    this->price = _other.price;
}

Item::~Item(){}

bool Item::operator==(const Item& _other) const {
    return _other.name == this->name && fabs(this->price - _other.price) < EPS;
}

void Item::set_name(const std::string& _name){
    this->name = _name;
}

void Item::set_price(const double& _price){
    this->price = _price;
}

std::ostream& operator<<(std::ostream& out, const Item& i){
    out << i.name << "." << i.price << "\n";
    return out;
}

#endif //!ITEM_CPP