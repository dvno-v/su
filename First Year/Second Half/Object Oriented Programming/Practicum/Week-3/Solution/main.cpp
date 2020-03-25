#include <iostream>
#include "Parking.cpp"


int main(){
    char name[] = "Goshi",
    brand[] = "fiat",
    brand2[] = "fiataaaa",
    brand3[] = "fiatbbbb",
    brand4[] = "fiacccct",
    licence_plate[] = "1234",
    colour[] = "white",
    fname[] = "mobilebg";
    int age = 19;
    bool has_licence = true;
    Person gosho(name, age, has_licence);
    Car punto(brand, licence_plate, colour, gosho);
    // punto.print_car();

    Car* cars = new Car[1];
    cars[0] = punto;
    Parking park(fname, gosho, cars, 1, 3);
    Car ne_punto(brand2, brand3, brand4, gosho);

    park.add_car(ne_punto);
    park.del_car(1);
    park.print_all();
    return 0;
}