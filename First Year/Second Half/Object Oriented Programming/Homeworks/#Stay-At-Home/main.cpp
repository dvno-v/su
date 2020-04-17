#include <iostream>

#include "User.cpp"



int main(){
    char a[] = "pesho", b[] = "p@abv.bg", _a[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    User u(a,10,b), c(a,80,b),v(a,10,b),n(a,10,b),q(a,10,b),m(_a,b);
    u.print();
    c.print();
    v.print();
    n.print();
    q.print();
    m.print();

    return 0;
}