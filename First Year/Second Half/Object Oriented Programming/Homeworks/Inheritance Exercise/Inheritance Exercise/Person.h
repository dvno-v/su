#ifndef PERSON_H


#define PERSON_H

class Person
{
public:
	Person(char* name = "", char* eng =  "");
	Person();
	~Person();
private:
	char* name;
	char* egn;
};

#endif // !PERSON_H



