#ifndef SUPERMARKET_H

#define SUPERMARKET_H

#include "Shop.h"
#include "./Task 1/Person.h"

//to-do

class Supermarket : public Shop
{
private:
    Person Owner;
public:
    Supermarket();
    ~Supermarket();
};

Supermarket::Supermarket(/* args */)
{
}

Supermarket::~Supermarket()
{
}


#endif //!SUPERMARKET_H