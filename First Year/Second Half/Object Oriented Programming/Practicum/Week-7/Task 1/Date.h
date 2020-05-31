#ifndef DATE_H
#define DATE_H

#include <ostream>

class Date {
private:
  int day, month, year;
public:
  Date();
  Date(int, int ,int);
  Date(const Date&);
  int get_day()const;
  int get_month()const;
  int get_year()const;

  friend std::ostream& operator<<(std::ostream&, const Date&);
};

#endif /* end of include guard: DATE_H */
