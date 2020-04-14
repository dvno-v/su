#ifndef __PERSON_CPP

#define __PERSON_CPP

#include "Person.h"
#include <cstring>
#include <iostream>


Person::Person()
{
	this->name = nullptr;
	this->passed_all_exams = false;
	this->age = 0;
	this->streight = false;
}

Person::Person(char* _name, bool _streight, int _age, bool _passed_all)
{
	this->name = this->copy_dynamic(_name);
	this->passed_all_exams = _passed_all;
	this->age = _age;
	this->streight = _streight;
}
Person::Person(const Person& other)
{
	this->copy(other);
}
Person& Person::operator=(const Person& other) {
	this->copy(other);
	return *this;
}
Person::~Person()
{
	this->erase_memory();
	std::cout << "Destructor called!" << std::endl;
}

char* Person::copy_dynamic(const char* from) {
	char* temp = new char[strlen(from) + 1];
	strcpy(temp, from);
	return temp;
}

void Person::erase_memory() {
	delete[] this->name;
}

void Person::print_if_passed() {
	std::cout << std::boolalpha << this->passed_all_exams << std::endl;
}

void Person::print_person()
{
	std::cout << "This person is " << this->name << " and he is " << this->age << " years old.\n";
}

void Person::copy(const Person& other) {
	this->name = this->copy_dynamic(other.name);
	this->age = other.age;
	this->passed_all_exams = other.passed_all_exams;
	this->streight = other.streight;
}

#endif // !__PERSON_CPP
