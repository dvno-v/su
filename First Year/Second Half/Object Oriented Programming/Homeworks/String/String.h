#ifndef STRING_H

#define STRING_H
#include <iostream>
#include <cstring>
#include <iostream>
#include <cassert>
class String
{
private:
    char* m_data;
    unsigned m_curr_size;
    void copy_memory(const char*);
    void erase_memory();
    void resize(unsigned&);
public:
    String();
    String(const char*);
    String(const String&);
    ~String();

	String& operator=(const String&);

	char& at(unsigned) const;
	char& operator[](unsigned) const;

	const char* front() const;
	const char* back() const;
	const char* data() const;

	bool empty();
	unsigned get_size() const;

	void clear();
	void insert(const char&, const unsigned&);

	void erase(const unsigned&, const unsigned&);
	void erase(const unsigned&);
	void erase(const char*, const char*);
	void erase(const char*);

	void push_back(const char&);
	char pop_back();
	void append(const char&);
	void operator+=(const char&);

	int compare(const String&);

    friend std::ostream& operator<< (std::ostream&, const String&);

};



#endif //!STRING_H