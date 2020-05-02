#ifndef PATIENT_CPP

#define PATIENT_CPP

#include "Patient.h"
#include <iostream>

Patient::Patient(): Person(), visits(0){}

Patient::Patient(std::string _name, const Date& _birth_date, int _visits):Person(_birth_date, name), visits(_visits){}

Patient::Patient(const Patient& _other): Person(_other), visits(_other.visits){}

Patient::~Patient(){
}

void Patient::new_visit(){
    ++this->visits;
}
int Patient::get_visits(){
    return this->visits;
}

void Patient::print(){
    std::cout << this->name << " " << this->birth_date;
}

#endif //!PATIENT_CPP