#ifndef CHALLENGE_CPP

#define CHALLENGE_CPP

#include <iostream>
#include <cstring>
#include <cassert>
#include "Challenge.h"

const unsigned MAX_CHALLENGE_NAME_LENGTH = 31;

Challenge::Challenge()
{
    this->name = copy_challenge_memory("");
    this->status = copy_challenge_memory("");
    this->rating = 0;
    this->times_called = 0;
}

Challenge::Challenge(const char* _name)
{
    assert(strlen(_name) > MAX_CHALLENGE_NAME_LENGTH);

    this->name = this->copy_challenge_memory(_name);
    this->status = this->copy_challenge_memory("new");
    this->times_called = 1;
    this->rating = 0;

}

Challenge::Challenge(const Challenge& _other)
{
    this->name = this->copy_challenge_memory(_other.name);
    this->status = this->copy_challenge_memory(_other.status);
    this->times_called = _other.times_called;
    this->rating = _other.rating;
}

Challenge::Challenge(const char* _name, unsigned _times_called , double _rating)
{
    assert(strlen(_name) > MAX_CHALLENGE_NAME_LENGTH);
    assert(_rating >= 5.0 && _rating <= 10);

    this->name = this->copy_challenge_memory(_name);
    this->times_called = _times_called;
    this->rating = _rating;
    if (this->times_called > 10) {
        this->status = this->copy_challenge_memory("old");
    }
    else if (this->times_called > 1) {
        this->status = this->copy_challenge_memory("quite recently");
    }
    else if (this->times_called == 1) {
        this->status = this->copy_challenge_memory("new");
    }
}

Challenge::~Challenge()
{
    this->del_challenge_memory("name");
    this->del_challenge_memory("status");
}


char* Challenge::copy_challenge_memory(char const* source) {
    char* temp = new char[strlen(source) + 1];
    strcpy_s(temp, strlen(source) + 1, source);
    return temp;
}

void Challenge::del_challenge_memory(char const* to_delete) {
    if (strcmp(to_delete, "status") == 0) {
        // std::cout << "deleted email\n"; 
        delete[] this->status;
    }
    if (strcmp(to_delete, "name") == 0) {
        // std::cout << "deleted name\n"; 
        delete[] this->name;
    }
}

void Challenge::update_rating(double _rating)
{
    double new_rating = this->rating * this->times_called;
    new_rating += _rating;
    new_rating /= (++this->times_called);
    this->rating = new_rating;
}

void Challenge::update_status()
{
    if (this->times_called > 10 && strcmp(this->status, "old") == 0) {
        this->del_challenge_memory("status");
        this->copy_challenge_memory("old");
    }
    else if (this->times_called > 1 && strcmp(this->status, "quite recently") == 0) {
        this->del_challenge_memory("status");
        this->copy_challenge_memory("quite recently");
    }
}

#endif //! CHALLENGE_CPP