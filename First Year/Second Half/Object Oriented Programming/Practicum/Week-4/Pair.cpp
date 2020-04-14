#pragma once
#include "Pair.h"
#include <iostream>
#include <cstring>

void Pair::print() const {
	std::cout << this->word << " -> " << this->meaning << '.' << std::endl;

}

bool Pair::operator==(const Pair& _other) const {
	return strcmp(this->word, _other.word) == 0 && strcmp(this->meaning, _other.meaning) == 0;
}
