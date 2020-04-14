#ifndef DICTIONARY_CPP

#define DICTIONARY_CPP

#include "Dictionary.h"
#include <iostream>
#include <cmath>
#include <algorithm>


Dictionary::Dictionary()
{
	this->size = 0;
}

Dictionary::Dictionary(Pair* _pairs, unsigned _size)
{
	_size = fmin(_size, MAX_SIZE_OF_DIC);
	for (unsigned i = 0; i < _size; i++)
	{
		this->word_meaning[i] = _pairs[i];
	}
	this->size = _size;
}

Dictionary::Dictionary(const Dictionary& _other)
{
	for (unsigned i = 0; i < _other.size; i++)
	{
		this->word_meaning[i] = _other.word_meaning[i];
	}
	this->size = _other.size;
}


void Dictionary::print() const {
	for (unsigned i = 0; i < this->size; i++)
	{
		this->word_meaning[i].print();
		std::cout << std::endl;
	}
	std::cout << "\n";
}

bool Dictionary::add(const Pair& _to_add) {
	if (this->size < MAX_SIZE_OF_DIC) {
		this->word_meaning[this->size++] = _to_add;
		return true;
	}
	else {
		std::cout << "Not enough space in the dictionary, please createa a new one\n";
		return false;
	}
}

bool Dictionary::remove(const char* _to_remove) {
	bool is_found = false;
	int pair_index = this->has_word(_to_remove);
	if (pair_index == -1) {
		return false;
	}
	for (unsigned i = pair_index; i < this->size; i++)
	{
		this->word_meaning[i] = this->word_meaning[i + 1];
	}
	--(this->size);
	return true;
}

char* Dictionary::get_meaning(char*_to_find) const
{
	for (unsigned i = 0; i < this->size; i++)
	{
		if (strcmp(this->word_meaning[i].word, _to_find) == 0) {
			char* temp = new char[strlen(this->word_meaning[i].meaning) + 1];
			strcpy_s(temp, strlen(this->word_meaning[i].meaning) + 1, this->word_meaning[i].meaning);
			return temp;
		}
	}
	return nullptr;
}

void Dictionary::print_all_words_alphabetically(){
	char**  temp = new char* [this->size];
	for (unsigned i = 0; i < this->size; i++)
	{
		temp[i] = this->word_meaning[i].word;
	}
	std::sort(temp, (temp + this->size), [](const char* lhs, const char* rhs){
			return strcmp(lhs, rhs) < 0;
		});
	for (size_t i = 0; i < this->size; i++)
	{
		this->word_meaning[this->has_word(temp[i])].print();
	}
	std::cout << "\n";
	delete[] temp;
}

unsigned Dictionary::has_pair(const Pair& _find) const
{
	for (unsigned i = 0; i < size; i++)
	{
		if (this->word_meaning[i] == _find) {
			return i;
		}
	}
	return -1;
}

unsigned Dictionary::has_word(const char* _find) const
{
	for (unsigned i = 0; i < size; i++)
	{
		if (strcmp(this->word_meaning[i].word, _find) == 0) {
			return i;
		}
	}
	return -1;
}




#endif // !DICTIONARY_H
