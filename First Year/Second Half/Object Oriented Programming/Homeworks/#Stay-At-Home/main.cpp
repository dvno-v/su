#include <iostream>

#include "Core.cpp"


int main(){
    char a[] = "pesho", b[] = "p@abv.bg", _a[101] = "gosho pesho tosho";
    // User u(a,10,b), c(a,80,b),v(a,10,b),n(a,10,b),q(a,10,b),m(a,b);
    // u.print();
    // c.print();
    // v.print();
    // n.print();
    // q.print();
    // m.print();
    // Challenge ch;
    Core c;
    // std::cin.getline(_a, 101);
    c.parse_input(_a);
    return 0;
}