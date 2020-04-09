#ifndef TIME_CPP

#define TIME_CPP
#include "Time.h"
#include <assert.h>
#include <math.h>

const unsigned MAX_HOURS = 23;
const unsigned MAX_MINUTES = 59;

Time::Time(): hours(0), minutes(0) {}

Time::Time(unsigned h, unsigned m) {
	assert(!(h > MAX_HOURS)); assert(!(m > MAX_MINUTES));
	hours = h;
	minutes = m;
}

Time::Time(const Time& other) {
	hours = other.hours;
	minutes = other.minutes;
}

Time::~Time(){
	hours = 0;
	minutes = 0;
}

void Time::set_h(unsigned h){
	assert(!(h > MAX_HOURS));
	hours = h;
}
void Time::set_m(unsigned m){
	assert(!(m > MAX_MINUTES));
	minutes = m;
}

unsigned Time::get_h() const{
	return hours;
}
unsigned Time::get_m() const{
	return minutes;
}

void Time::add_m(unsigned m){
	minutes += m;
	unsigned hours_to_add = (minutes / 60);
	if (minutes) {
		minutes %= 60;
	}
	hours += hours_to_add;
	hours %= 24;
}
unsigned Time::get_minutes_from_zero_oclock() const{
	return hours * 60 + minutes;
}

bool Time::operator==(const Time& other){
	return other.hours == hours && other.minutes == minutes;
}
bool Time::operator>(const Time& other){
	if (other.hours > hours) {
		return false;
	}
	else if (other.hours < hours) {
		return true;
	}
	else {
		return minutes > other.minutes;
	}
}
bool Time::operator<(const Time& other){
	return !((*this) > other);
}
bool Time::operator>=(const Time& other){
	return (*this) > other || (*this) == other;
}
bool Time::operator<=(const Time& other){
	return !((*this) >= other);
}

Time Time::operator+(const Time& other){
	unsigned minutes_to_add = other.get_minutes_from_zero_oclock();
	Time temp(*this);
	temp.add_m(minutes_to_add);
	return temp;
}
Time Time::operator-(const Time& other){
	unsigned time1 = get_minutes_from_zero_oclock(), time2 = other.get_minutes_from_zero_oclock();
	Time temp;
	temp.add_m(fabs(time1 - time2));
	return temp;
}
Time Time::operator*(unsigned multiply){
	unsigned minutes_to_add = get_minutes_from_zero_oclock() * (multiply);
	Time temp;
	temp.add_m(minutes_to_add);
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Time& t)
{
	out << t.hours << ":" << t.minutes << "\n";
	return out;
}

#endif // !TIME_CPP


