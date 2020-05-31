#ifndef DOCTOR_H

#define DOCTOR_H

#include <vector>
#include "Person.h"
#include "Patient.h"

class Doctor : public Person
{
private:
    std::vector<Patient*> patients;
    int all_visits;
public:
    Doctor();
    Doctor(const std::string&, const Date&);
    Doctor(const std::string&, const Date&, const std::vector<Patient *>);
    Doctor(const std::string&, const Date&, const std::vector<Patient *>, int);
    Doctor(const Doctor&);
    ~Doctor();

    double get_average_visits() const;
    void add_patient(Patient*);
    void print_users_with_more_visits(int = 0) const;
};

#endif //!DOCTOR_H