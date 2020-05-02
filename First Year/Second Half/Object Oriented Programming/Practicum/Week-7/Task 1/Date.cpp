#ifndef DATE_CPP
#define DATE_CPP


#include "Date.h"

Date::Date(): day(1), month(1), year(1900){}

Date::Date(int _day, int _month, int _year): day(_day), month(_month), year(_year){}

Date::Date(const Date& _other): day(_other.day), month(_other.month), year(_other.year){}

int Date::get_day()const{
  return this->day;
}
int Date::get_month()const{
  return this->month;
}
int Date::get_year()const{
  return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& d){
  out << d.day << "  " << d.month << "  " << d.year << " \n";

  return out;
}

#endif /* end of include guard: DATE_CPP */
