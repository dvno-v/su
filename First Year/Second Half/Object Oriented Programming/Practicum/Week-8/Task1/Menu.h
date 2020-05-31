#ifndef MENU_H

#define MENU_H

#include <vector>
#include "Food.h"


class Menu
{
private:
    std::vector<Food*> foods;
    Food* get_food_by_id(int) const;
public:
    Menu();
    Menu(std::vector<Food*>);
    ~Menu();
    void add_food(Food&);
    void consume_food(int, int);
    Food* get_cheapest() const;
};




#endif
