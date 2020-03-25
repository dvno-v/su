#ifndef __PERSON_H

#define __PERSON_H


class Person
{
private:
    char* name;
    int age;
    bool has_licence;

    char* copy_dynamic(char*);
    void copy_person(const Person&);
    void delete_dynamic();

public:
    //construction
    Person();
    Person(const Person&);
    Person(char*, const int&, const bool&);
    ~Person();
    
    //eq
    Person& operator=(const Person&);
    bool operator==(const Person&);

    void set_name(char*);
    void set_age(const int&);
    void set_licence(const bool&);

    char* get_name() const;
    int get_age() const;
    bool get_if_licence() const;

    void print_person() const;
};



#endif // !__PERSON_H