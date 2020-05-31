#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Date.h"

class Person{
protected:
  Date birth_date;
  std::string name;

  void del_memory();
public:
  Person();
  Person(const Date&, std::string);
  Person(const Person&);
  Person& operator=(const Person&);
  ~Person();

};


#endif /* end of include guard: PERSON_H */
