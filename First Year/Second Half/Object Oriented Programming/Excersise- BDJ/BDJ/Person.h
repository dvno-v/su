#ifndef __PERSON_H

#define __PERSON_H

class Person
{
public:
	Person();
	Person(char*, bool, int, bool);
	Person(const Person&);
	Person &operator=(const Person&);
	~Person();

	void print_if_passed();
	void print_person();
private:
	char* name;
	bool streight;
	int age;
	bool passed_all_exams;
	char* copy_dynamic(const char*);
	void erase_memory();
	void copy(const Person&);
};

#endif // !__PERSON_H
