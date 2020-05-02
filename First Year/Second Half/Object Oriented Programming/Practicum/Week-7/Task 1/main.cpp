#include <iostream>

#include "Patient.h"
#include "Doctor.h"

int main(){
  Patient a;
  Doctor b;
  a.print();

  b.add_patient(&a);
  b.add_patient(&a);
  b.add_patient(&a);
  b.add_patient(&a);
  b.add_patient(&a);
  b.add_patient(&a);

  b.print_users_with_more_visits();
  std::cout << b.get_average_visits();

  return 0;
}
