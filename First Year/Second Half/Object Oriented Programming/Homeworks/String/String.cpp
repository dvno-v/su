#ifndef STRING_CPP

#define STRING_CPP
#include "String.h"

void String::copy_mem(const char* _data) {
	unsigned _data_lenght = strlen(_data);
	this->data = new char[_data_lenght + 1];
	for (unsigned i = 0; i < _data_lenght; i++)
	{
		this->data[i] = _data[i];
	}
	this->data[_data_lenght] = '\0';
}


void String::erase() {
	delete[] this->data;
}

String::String()
{
	this->data = nullptr;
	this->size = 0;
	this->capacity = 0;
}

String::~String()
{
	this->erase();
}

#endif // !STRING_CPP

