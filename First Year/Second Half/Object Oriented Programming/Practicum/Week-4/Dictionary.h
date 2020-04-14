#ifndef DICTIONARY_H

#define DICTIONARY_H
#include "Pair.h"

const int MAX_SIZE_OF_DIC = 500;



class Dictionary
{
public:
	Dictionary();
	Dictionary(Pair*, unsigned);
	Dictionary(const Dictionary&);

	void print() const;
	bool add(const Pair&);
	bool remove(const char*);
	char* get_meaning(char*) const;
	void print_all_words_alphabetically();
	unsigned has_pair(const Pair&) const;
	unsigned has_word(const char*) const;

private:
	Pair word_meaning[MAX_SIZE_OF_DIC];
	unsigned size;
};


#endif // !DICTIONARY_H
