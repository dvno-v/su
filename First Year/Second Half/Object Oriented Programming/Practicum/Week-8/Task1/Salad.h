#ifndef SALAD_H

#define SALAD_H

#include "Food.h"

class Salad : public Food
{
private:
    int number_of_products;
    bool ovkusena;
public:
    Salad(std::string, double, int, int, int, int, bool);
    ~Salad();

    void print() const;

};



#endif