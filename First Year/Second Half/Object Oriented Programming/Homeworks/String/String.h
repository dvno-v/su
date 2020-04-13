#ifndef STRING_H

#define STRING_H
#include <cstring>
#include <iostream>

class String
{
public:
	String();
	String(const char*);
	String(const String&);
	~String();

	//String& operator=(const String&);

	//char& at(unsigned) const;
	//char& operator[](unsigned) const;

	//char* front() const;
	//char* back() const;
	//char* data() const;

	//bool empty() const;
	//unsigned get_size() const;
	//unsigned get_curr_capacity() const;
	//bool reserve();

	//bool clear();
	//bool reserve();
	//bool insert(const char&, const unsigned&);

	//bool erase(const unsigned&, const unsigned&);
	//bool erase(const unsigned&);
	//bool erase(const char*, const char*);
	//bool erase(const char*);

	//bool push_back(const char&);
	//char pop_back();
	//bool append(const char&);
	//void operator+=(const char&);

	//int compare(const String&);

	//bool starts_with(const char&);
	//bool ends_with(const char&);

	//bool replace(const unsigned&, const char&);
	//bool copy_str(const String&);
	//bool delete_str();
	//bool swap(const char*, const char*);

	//friend std::iostream& operator<<(std::iostream&, const String&);
private:
	char* data;
	unsigned size;
	unsigned capacity;
	void copy_mem(const char*);
	void erase();
};


#endif // !STRING_H
