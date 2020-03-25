#ifndef __CAR_H

#define __CAR_H

#include "Person.cpp"

class Car
{
private:
    char* brand;
    char* licence_plate;
    char* colour;
    Person owner;

    char* copy_dynamic(char*);
    void copy_car(const Car&);
    void delete_dynamic();
public:
    Car();
    Car(const Car&);
    Car(char*, char*, char*, const Person&);
    ~Car();

    void set_brand(char*);
    void set_licence_plate(char*);
    void set_colour(char*);
    void set_owner(const Person&);

    char* get_brand() const;
    char* get_licence_plate() const;
    char* get_colour() const;
    Person get_owner() const;
    
    Car& operator=(const Car&);
    bool operator==(const Car&);

    void print_car() const;
    bool if_owner_can_drive() const;
};



#endif // !__CAR_H