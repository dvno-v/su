#ifndef SHOP_CPP

#define SHOP_CPP

#include "Shop.h"
#include <iostream>
#include <fstream>

void Shop::read_from_file(std::fstream& in){
    char temp[150];
    std::string temp_str;
    double price;
    Item to_add_item;
    while(in){
        in.getline(temp, 150, '.');
        
        temp_str = temp;
        in >> price;
        
        in.ignore();

        if(!this->is_full() && temp_str != ""){
            to_add_item.set_name(temp_str);
            to_add_item.set_price(price);
            this->add_item(to_add_item);
        } else{
            break;
        }
    }
}


Shop::Shop(){}

Shop::Shop(std::vector<Item> _items, const int& _max_items){
    this->items = _items;
    this->max_items = _max_items;
}
Shop::Shop(std::fstream& in, const int& _max_items){
    this->max_items = _max_items;
    this->read_from_file(in);
}

Shop::~Shop(){}

bool Shop::add_item(const Item& to_add){
    if(!this->is_full()){
        this->items.push_back(to_add);
        return true;
    }
    return false;
}

bool Shop::add_item(const std::string& _name, const double& _price){
    if(!this->is_full()){
        this->items.emplace_back(_name, _price);
        return true;
    }
    return false;
}

bool Shop::find_item(const Item& to_find) const {
    for (int i = 0; i < this->items.size(); i++)
    {
        if(this->items[i].operator==(to_find)){
            return true;
        }
    }
    return false;
    
}

void Shop::save_to_file(const char* file_name) const {
    std::fstream i_file(file_name);

    for (int i = 0; i < this->items.size(); i++)
    {
        i_file << this->items[i];
    }
    i_file.close();
}

bool Shop::is_full() const{
    if(this->items.size() >= this->max_items){
        return true;
    }
    return false;
}

void Shop::print() const{
    for (int i = 0; i < this->items.size(); i++)
    {
        std::cout << this->items[i];
    }
    
}

#endif //!SHOP_CPP