#ifndef TIME_H

#define TIME_H
#include <iostream>
class Time
{
public:
	Time();
	Time(unsigned, unsigned);
	Time(const Time&);
	~Time();
	
	void set_h(unsigned);
	void set_m(unsigned);

	unsigned get_h() const;
	unsigned get_m() const;

	void add_m(unsigned);
	unsigned get_minutes_from_zero_oclock() const;

	bool operator==(const Time&);
	bool operator>(const Time&);
	bool operator<(const Time&);
	bool operator>=(const Time&);
	bool operator<=(const Time&);

	Time operator+(const Time&);
	Time operator-(const Time&);
	Time operator*(unsigned);

	friend std::ostream& operator<<(std::ostream&, const Time&);
private:
	unsigned hours;
	unsigned minutes;
};

#endif // !TIME_H


