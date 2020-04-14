#pragma once

const int MAX_WORD_SIZE = 101;
const int MAX_MEANING_SIZE = 501;

struct Pair {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
	void print() const;
	bool operator==(const Pair&) const;
};
