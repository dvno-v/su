#include <iostream>
#include <cstring>
#include <fstream>

#define MAX_SIZE 1024

struct Animal{
    char* type;
    char* name;
    int age;
};

char* copyDynamic(char* source){
    char* result = new char[strlen(source) + 1];
    strcpy(result, source);
    return result;
}

void deleteDynamic(Animal& a){
    delete[] a.type;
    delete[] a.name;
}

void initialize(Animal& a){
    char input[1024];

    std::cin.ignore();
    std::cin.getline(input, MAX_SIZE);
    a.type = copyDynamic(input);
    
    std::cin.getline(input, MAX_SIZE);
    a.name = copyDynamic(input);

    std::cin >> a.age;
}

struct Zoo{
    char* name;
    Animal* animals;
    int count;
    int capacity;
};

void initializeZoo(Zoo& z, char* name, Animal* animls, int size, int capacity){
    z.name = copyDynamic(name);
    z.animals = new Animal[capacity];

    for(int i = 0; i < size; i++){
        z.animals[i] = animls[i];
    }

    z.count = size;
    z.capacity = capacity;
}

bool hasSpicies(const Zoo& z, char* species){
    for(int i = 0; i < z.count; i++){
        if(strcmp(z.animals[i].type, species) == 0){
            return true;
        }
    }

    return false;
}

void printAnimal(Animal a){
    std::cout << "\n--------------Animal--------------\n"
              << "Type:"
              << a.type
              << std::endl
              << "Name:"
              << a.name
              << std::endl
              << "Age:"
              << a.age
              << std::endl;
}

int main(){
    int n;
    char species[MAX_SIZE];
    
    std::cout << "Input number of animals:";
    std::cin >> n;

    Animal* animals = new Animal[n];

    for(int i = 0; i < n; i++){
        initialize(animals[i]);
    }

    for(int i = 0; i < n; i++){
        printAnimal(animals[i]);
    }

    
    Zoo myZoo;
    initializeZoo(myZoo, "Bochka Zoo", animals, n, 2*n);

    std::cout << "Input species type :";
    std::cin >> species;

    std::cout << "There are species type "
              << species 
              << " : " 
              << std::boolalpha 
              << hasSpicies(myZoo, species) 
              << std::endl;  
    
    for(int i = 0; i < n; i++){
        deleteDynamic(animals[i]);
    }  
    delete[] animals;

    return 0;
}