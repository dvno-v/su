#ifndef USER_CPP

#define USER_CPP

#include <iostream>
#include <cstring>
#include <cassert>
#include <climits>
#include "User.h"

const unsigned MAX_EMAIL_LENGTH = 101;
const unsigned MAX_AGE = 90;
const unsigned MAX_NAME_LENGTH = 101;
const unsigned NO_AGE = UINT_MAX;

char* User::copy_user_memory(char const* source) {
	char* temp = new char[strlen(source) + 1];
	strcpy_s(temp, strlen(source) + 1, source);
	return temp;
}

void User::del_user_memory(char const* to_delete) {
	if (strcmp(to_delete, "email") == 0) {
		// std::cout << "deleted email\n";
		delete[] this->email;
	}
	if (strcmp(to_delete, "name") == 0) {
		// std::cout << "deleted name\n";
		delete[] this->name;
	}
	if (strcmp(to_delete, "challenges") == 0) {
		// std::cout << "deleted challenges\n";
		delete[] this->challenges;
	}
}

User::User(const char* _name, unsigned _age, const char* _email) {
	assert(strlen(_name) < MAX_NAME_LENGTH);
	assert(strlen(_email) < MAX_EMAIL_LENGTH);
	assert(_age <= MAX_AGE && _age >= 1);

	this->unique_id = reinterpret_cast<unsigned long>(this);
	this->age = _age;
	this->name = copy_user_memory(_name);
	this->email = copy_user_memory(_email);
	this->number_of_challenges = 0;
	this->challenges = nullptr;
}

User::User(const char* _name, unsigned _age) {
	assert(strlen(_name) < MAX_NAME_LENGTH);
	assert(_age <= MAX_AGE && _age >= 1);

	this->unique_id = reinterpret_cast<unsigned long>(this);
	this->age = _age;
	this->name = copy_user_memory(_name);
	this->email = copy_user_memory("Unknown");
	this->challenges = nullptr;
	this->number_of_challenges = 0;
}

User::User(const char* _name, const char* _email) {
	assert(strlen(_name) < MAX_NAME_LENGTH);
	assert(strlen(_email) < MAX_EMAIL_LENGTH);

	this->unique_id = reinterpret_cast<unsigned long>(this);
	this->age = NO_AGE;
	this->name = copy_user_memory(_name);
	this->email = copy_user_memory(_email);
	this->number_of_challenges = 0;
	this->challenges = nullptr;
}

User::User(const char* _name) {
	assert(strlen(_name) < MAX_NAME_LENGTH);

	this->unique_id = reinterpret_cast<unsigned long>(this);
	this->age = NO_AGE;
	this->name = copy_user_memory(_name);
	this->email = copy_user_memory("Unknown");
	this->number_of_challenges = 0;
	this->challenges = nullptr;
}

User::User(const User& _other) {
	this->unique_id = reinterpret_cast<unsigned long>(this);
	this->name = copy_user_memory(_other.name);
	this->age = _other.age;
	this->email = copy_user_memory(_other.email);

	this->challenges = new Challenge * [_other.number_of_challenges];
	for (unsigned i = 0; i < _other.number_of_challenges; i++)
	{
		this->challenges[i] = _other.challenges[i];
	}
	this->number_of_challenges = _other.number_of_challenges;
}

User::~User() {
	this->del_user_memory("name");
	this->del_user_memory("email");
	this->del_user_memory("challenges");
}

const unsigned User::get_unique_id() const {
	return this->unique_id;
}

const char* User::get_name() const {
	return this->name;
}

void User::add_challenge(Challenge* to_add) {
	Challenge** temp = new Challenge * [this->number_of_challenges + 1];
	for (unsigned i = 0; i < this->number_of_challenges; i++)
	{
		temp[i] = this->challenges[i];
	}
	temp[this->number_of_challenges++] = to_add;
	this->del_user_memory("challenges");
	this->challenges = temp;
}

void User::remove_challenge_from_user(Challenge* finished) {
	if (this->number_of_challenges >= 2) {
		Challenge** temp = new Challenge * [this->number_of_challenges - 1];
		bool passed_ch = false;
		for (unsigned i = 0; i < number_of_challenges; i++)
		{
			if (this->challenges[i] == finished) {
				passed_ch = true;
			}
			if (passed_ch)
			{
				temp[i] = this->challenges[i + 1];
			}
			else {
				temp[i] = this->challenges[i];
			}
		}

		this->del_user_memory("challenges");
		this->challenges = temp;
		--this->number_of_challenges;
	}
	else {
		this->del_user_memory("challenges");
		this->challenges = nullptr;
		this->number_of_challenges = 0;
	}
}

void User::print() const {
	std::cout << "Name: " << this->name << "\nAge: ";
	if (this->age == NO_AGE) {
		std::cout << "Unknown";
	}
	else {
		std::cout << this->age;
	}
	std::cout << "\nEmail: " << this->email << "\nId: " << this->unique_id << "\n";
	if (this->number_of_challenges > 0) {
		std::cout << "USER CHALLENGES:\n";
		this->print_user_challenges();
	}
}

void User::print_user_challenges() const
{
	for (unsigned i = 0; i < this->number_of_challenges; i++)
	{
		this->challenges[i]->print_ch();
	}
}

#endif // !USER_CPP