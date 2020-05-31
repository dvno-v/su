#ifndef DOCTOR_CPP

#define DOCTOR_CPP

#include <iostream>
#include <algorithm>
#include "Doctor.h"

Doctor::Doctor():Person(), all_visits(0){}

Doctor::Doctor(const std::string& _name, const Date& _date): Person(_date, _name), all_visits(0){}

Doctor::Doctor(const std::string& _name, const Date& _date, const std::vector<Patient *> _patients):Person(_date, _name), patients(_patients), all_visits(_patients.size()){}

Doctor::Doctor(const std::string& _name, const Date& _date, const std::vector<Patient *> _patients, int _all_visits):Person(_date, _name), patients(_patients), all_visits(_all_visits){}

Doctor::Doctor(const Doctor&_other):Person(_other), patients(_other.patients), all_visits(_other.all_visits){}

Doctor::~Doctor(){}

double Doctor::get_average_visits() const{
    if(this->all_visits == 0){
        return 0;
    }
    std::cout << this->all_visits << "  " << this->patients.size() << "\n";
    return static_cast<double>(this->all_visits) / this->patients.size();
}

void Doctor::add_patient(Patient* _to_add){
    if (std::find(this->patients.begin(), this->patients.end(), _to_add) == this->patients.end())
        this->patients.push_back(_to_add);
    ++this->all_visits;
    _to_add->new_visit();
}

void Doctor::print_users_with_more_visits(int more) const{
    for (int i = 0; i < this->patients.size(); i++)
    {
        if(this->patients[i]->get_visits() >= more){
            this->patients[i]->print();
            std::cout << "\n";
        }
    }
}


#endif //!DOCTOR_CPP