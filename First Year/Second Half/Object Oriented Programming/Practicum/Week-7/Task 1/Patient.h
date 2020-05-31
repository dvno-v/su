#ifndef PATIENT_H

#define PATIENT_H

#include "Person.h"

class Patient : public Person
{
private:
    int visits;
public:
    Patient();
    Patient(std::string, const Date&, int);
    Patient(const Patient&);
    ~Patient();

    void new_visit();
    int get_visits();

    void print();

};


#endif //!PATIENT_H