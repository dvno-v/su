#ifndef DATE_H

#define DATE_H

#include <iostream>

class Date
{
private:
	unsigned year;
	unsigned month;
	unsigned day;

	bool is_leap_year(const unsigned&) const;
public:
	Date();
	Date(const unsigned&, const unsigned&, const unsigned&);
	Date(const Date&);
	~Date();

	Date& operator=(const Date&);

	void set_year(const unsigned&);
	void set_month(const unsigned&);
	void set_day(const unsigned&);

	unsigned get_day() const;
	unsigned get_month() const;
	unsigned get_year() const;

	void is_valid_input(const unsigned&, const unsigned&, const unsigned&) const;

	friend std::ostream& operator<<(std::ostream&, const Date&);

	bool operator>(const Date&) const;
	bool operator<(const Date&) const;
	bool operator==(const Date&) const;
	bool operator>=(const Date&) const;
	bool operator<=(const Date&) const;
};

#endif
