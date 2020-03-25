#include <iostream>
#include <fstream>

#define NAME_SIZE 16
#define FACULTY_NUMBER_SIZE 6

struct Student
{
    char name[NAME_SIZE];
    char fnumber[FACULTY_NUMBER_SIZE];
    int age;
};

void printStudent(const Student& s){
    std::cout << "\n--------------Student--------------\n"
              << "Name:"
              << s.name
              << std::endl
              << "FNumber:"
              << s.fnumber
              << std::endl
              << "Age:"
              << s.age
              << std::endl;
}

int main()
{
    int n;
    Student* students;  
    
    std::cin >> n;  

    students = new Student[n];

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> students[i].name;
        std::cin >> students[i].fnumber;
        std::cin >> students[i].age;
    }

    std::ofstream outputFile("students.data", std::ios::binary);
    outputFile.write((char*) &*students, sizeof(Student) * n);
    outputFile.close();
    
    std::ifstream inputFile("students.data", std::ios::binary | std::ios::ate);

    n = inputFile.tellg() / sizeof(Student);
    
    std::cout << "Size: " << n << std::endl;

    Student* st = new Student[n];

    inputFile.seekg(0);

    inputFile.read((char*) &*st, sizeof(Student)* n);

    inputFile.close();

    for(int i = 0; i < n; i++){
        printStudent(st[i]);
    }

    delete[] students;
    
    return 0;
}