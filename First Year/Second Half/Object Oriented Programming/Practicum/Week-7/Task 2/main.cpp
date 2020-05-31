#include <iostream>
#include <fstream>

#include "Shop.cpp"

int main(){
    // Shop asd;
    // Item i, i2("peshko", 3.1), i3(i2);
    // asd.add_item(i);
    // asd.add_item(i2);
    // asd.add_item(i3);
    // asd.add_item(i);
    // asd.add_item(i);
    // asd.add_item(i);
    // asd.add_item(i);
    // asd.add_item(i);
    // asd.add_item(i);
    // asd.add_item(i);
    // asd.save_to_file("Shop.txt");

    // asd.print();

    std::fstream in;
    in.open("Shop.txt");
    
    Shop sh(in, 150);

    sh.print();
    return 0;
}