#ifndef DATE_CPP

#define DATE_CPP

#include "Date.h"
#include <cassert>
#include <string>

bool Date::is_leap_year(const unsigned& year) const{
	if (year % 400 == 0) {
      return true;
   }
   else if (year % 100 == 0) {
      return false;
   }
   else if (year % 4 == 0) {
      return true;
   }
   else {
      return false;
   }
}

Date::Date(){
	this->year = 1900;
	this->month = 1;
	this->day = 1;
}

Date::Date(const unsigned& _year, const unsigned& _month, const unsigned& _day){
	this->is_valid_input(_year, _month, _day);
	this->set_year(_year);
	this->set_month(_month);
	this->set_day(_day);
}

Date::Date(const Date& _other){
	this->set_year(_other.year);
	this->set_month(_other.month);
	this->set_day(_other.day);
}

Date::~Date(){}

Date& Date::operator=(const Date& _other){
	if(this != &_other){
		this->set_year(_other.year);
		this->set_month(_other.month);
		this->set_day(_other.day);
	}
	return *this;
}

void Date::set_year(const unsigned& _year){
	this->year = _year;
}

void Date::set_month(const unsigned& _month){
	this->month = _month;
}

void Date::set_day(const unsigned& _day){
	this->day = _day;
}

unsigned Date::get_day() const{
	return this->day;
}
unsigned Date::get_month() const{
	return this->month;
}
unsigned Date::get_year() const{
	return this->year;
}

void Date::is_valid_input(const unsigned& _year, const unsigned& _month, const unsigned& _day) const{
	int max_days = 28;
	switch(_month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			max_days += 3;
			break;
		case 2:
			if(this->is_leap_year(_year)){
				max_days += 1;
			}
			break;
		default:
			max_days += 2;
			break;

	}
	assert(_day <= 31 && _day >= 1 && _day <= max_days);
	assert(_month <= 12 && _month >=1);
	assert(_year >= 1900);
}

std::ostream& operator<<(std::ostream& out, const Date& d){
	out << d.year << "-" << d.month << "-" << d.day ;
	return out;
}

bool Date::operator>(const Date& _other) const{
	if(this->year > _other.year){
		return true;
	}else if(this->year == _other.year ){
		if(this->month > _other.month){
			return true;
		}
		else if(this->month == _other.month){
			if(this->day > _other.day){
				return true;
			}
		}
	}
	return false;
}

bool Date::operator<(const Date& _other) const{
	return !((*this) > _other);
}

bool Date::operator==(const Date& _other) const{
	return this->year == _other.year && this->month == _other.month && this->day == _other.day;
}

bool Date::operator>=(const Date& _other) const{
	return ((*this) > _other) || ((*this) == _other);
}

bool Date::operator<=(const Date& _other) const{
	return ((*this) < _other) || ((*this) == _other);
}



#endif