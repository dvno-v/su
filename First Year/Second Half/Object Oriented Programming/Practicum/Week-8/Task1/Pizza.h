#ifndef PIZZA_H

#define PIZZA_H

#include "Food.h"
#include <string>

class Pizza : public Food
{
private:
    std::string type_of_pizza;
public:
    Pizza(std::string, std::string, double, int, int, int);
    ~Pizza();

    void print() const;
};




#endif