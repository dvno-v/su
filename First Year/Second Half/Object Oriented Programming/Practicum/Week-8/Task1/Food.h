#ifndef FOOD_H

#define FOOD_H

#include <string>

class Food
{
protected:
    std::string name;
    std::string category;
    double price_per_portion;
    int id;
    int grams;
    int available_portions;
    int grams_per_portion;

    void set_id();
public:
    Food(std::string, std::string, double, int, int, int);
    ~Food();

    void consume();

    int get_id() const;
    double get_price() const;
    std::string get_category() const ;

    void print() const;
};

#endif // !FOOD_H