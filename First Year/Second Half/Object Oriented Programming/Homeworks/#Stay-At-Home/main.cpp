#include <iostream>

#include "User.h"


int main(){
    char a[] = "pesho", b[] = "p@abv.bg", _a[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    User u(a,10,b), c(a,80,b),v(a,10,b),n(a,10,b),q(a,10,b),m(a,b);
    u.print();
    c.print();
    v.print();
    n.print();
    q.print();
    m.print();
    Challenge ch;
    std::cout << sizeof(ch);
    return 0;
}