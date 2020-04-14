#include <iostream>
#include "StringImpl.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    String a;
    a.push_back('a');
    a.push_back('b');
    a.push_back('c');
    a.push_back('d');
    a.push_back('f');
    a.push_back('e');
    a.push_back('g');
    a.push_back('i');
    a.push_back('j');
    a.push_back('k');
    std::cout << a;
    a.insert('z', 3);
    std::cout << a;
    a.pop_back();
    a.pop_back();
    std::cout << a;
    a.clear();
    std::cout << a;
    for (int i = 0; i < 10; i++)
    {
        a.push_back('a');
    }
    a.insert('b', 1);
    
    std::cout << a;
    return 0;
}
