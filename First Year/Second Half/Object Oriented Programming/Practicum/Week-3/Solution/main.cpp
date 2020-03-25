#include <iostream>
#include "Person.cpp"


int main(){
    char name[] = "gosho";
    Person a(name, 12, false);

    Person b(a);

    b.print_person();

    std::cout << (a == b);
    

    return 0;
}