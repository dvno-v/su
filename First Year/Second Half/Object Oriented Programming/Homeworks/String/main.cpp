#include <iostream>
#include "StringImpl.h"

int main(){
    String a("Gosho");
    a.insert('a', 2);
    operator<<(std::cout, a);
}