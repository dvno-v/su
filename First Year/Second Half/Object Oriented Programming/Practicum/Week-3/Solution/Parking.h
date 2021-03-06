#ifndef __PARKING_H

#define __PARKING_H

#include "Car.cpp"

class Parking
{
private:
    char* fname;
    Person owner;
    Car* cars;
    size_t cars_count;
    size_t capacity;

    void copy_parkings(const Parking&);
    char* copy_dynamic(char*);
    void delete_parking();
    void copy_park(const Parking&);
public:
    Parking();
    Parking(const Parking&);
    Parking(char*, const Person&, Car*, size_t, size_t);
    ~Parking();

    Parking& add_car(const Car&);
    Parking& del_car(const int&);

    Person get_owner(char*);
    void print_all_owned_by_owner(const Person&);
    void print_all();
};

#endif