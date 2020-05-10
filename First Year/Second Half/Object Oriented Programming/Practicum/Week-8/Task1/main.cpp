#include <iostream>
#include "Menu.h"
#include "Pizza.h"
#include "Salad.h"
int main(){
    Pizza p("Margarita", "S domati", 13.5, 1300, 10, 10);
    Salad s("Salata", 13.10, 1400, 11, 11, 8, true);
    p.print();
    s.print();
    Menu m;
    m.add_food(p);
    m.add_food(s);
    m.print_cheapest();
    return 0;
}