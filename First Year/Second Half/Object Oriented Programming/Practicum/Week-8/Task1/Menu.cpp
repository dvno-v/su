#ifndef MENU_CPP

#define MENU_CPP
#define EPS 0.000001

#include "Menu.h"
#include "Salad.h"
#include "Pizza.h"
#include "math.h"

Menu::Menu(){}

Menu::Menu(std::vector<Food*> _foods){
    this->foods = _foods;
}

Menu::~Menu(){}

Food* Menu::get_food_by_id(int id) const{
    for (int i = 0; i < this->foods.size(); i++)
    {
        if(this->foods[i]->get_id() == id){
            return this->foods[i];
        }
    }
    return nullptr;
}


void Menu::add_food(Food& to_add){
    this->foods.push_back(&to_add);
}
void Menu::consume_food(int id, int portions){
    Food* needed_food = this->get_food_by_id(id);
    for (int i = 0; i < portions; i++)
    {
        needed_food->consume();
    }
}
Food* Menu::get_cheapest() const{
    double cheapest_price = this->foods[0]->get_price();
    Food* cheapest_food = this->foods[0];
    for (int i = 1; i < this->foods.size(); i++)
    {
        if(cheapest_price - this->foods[i]->get_price() <= EPS){
            cheapest_food = this->foods[i];
            cheapest_price = this->foods[i]->get_price();
        }
    }
    return cheapest_food;
}

#endif //MENU_CPP