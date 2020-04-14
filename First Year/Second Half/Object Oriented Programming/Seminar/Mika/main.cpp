#include <iostream>
#include <cstring>
#include <fstream>

class Egg{
public:
    Egg() : name(nullptr), size(0) {}
    Egg(const char* _name, unsigned _size) : name(nullptr){
        setName(_name);
        setSize(_size);
    }

    Egg(const Egg& egg) : name(nullptr){
        setName(egg.name);
        setSize(egg.size);
    }
    Egg& operator=(const Egg& egg){
        if ( this != &egg){
            setName(egg.name);
            setSize(egg.size);
        }
        return *this;
    }
    ~Egg(){
        delete[] name;
    }

    const char* getName() const {
        return name;
    }
    unsigned getSize() const {
        return size;
    }

    bool setName(const char* _name){
        char* newName = new (std::nothrow) char[strlen(_name) +1];
        if(newName == nullptr)
            return false;
        delete[] name;
        name = newName;

        strcpy(name, _name);
        return true;
    }
    bool setSize(unsigned _size){
        size = _size;
        return true;
    }
private:
    char* name;
    unsigned size;
};

class Basket{
    Basket() : owner(nullptr), eggs(nullptr), numberOfEggs(0), capacity(0){}
    Basket(const char* filename) {
        std::ifstream in(filename, std::ios::binary);
        // дължина на име - име - брой яйца - дължина на името - името - размер на яйцето
        unsigned nameLength;
        in.read((char*)&nameLength, sizeof(nameLength));
        char* name = new (std::nothrow) char[nameLength+1];
        in.read(name, nameLength);

        in.read((char*)&numberOfEggs, sizeof(numberOfEggs));
        eggs = new (std::nothrow) Egg[numberOfEggs];
        for(int i = 0; i<numberOfEggs ; ++i){
            unsigned eggNameLength;
            in.read((char*)&eggNameLength, sizeof(eggNameLength));
            char* eggName = new (std::nothrow) char[eggNameLength+1];
            in.read(eggName, eggNameLength);
            eggs[i].setName(eggName);

            unsigned eggSize;
            in.read((char*)&eggSize, sizeof(eggSize));
            eggs[i].setSize(eggSize);
        }
        capacity = numberOfEggs;
        in.close();

    }
    Basket(const Basket& rhs) : owner(nullptr), eggs(nullptr){   // rhs == right hand-side
        setOwner(rhs.owner);
        setEggs(rhs.eggs, rhs.numberOfEggs);
    }

    Basket& operator=(const Basket& rhs) {
        if (this != &rhs) {
            setOwner(rhs.owner);
            setEggs(rhs.eggs, rhs.numberOfEggs);
        }
        return *this;
    }

    ~Basket(){
        delete [] owner;
        delete[] eggs;
    }

    bool setOwner(const char* name){
        char* newName = new (std::nothrow) char[strlen(name) +1];
        if(newName == nullptr)
            return false;
        delete[] owner;
        owner = newName;

        strcpy(owner, name);
        return true;
    }
    bool setEggs(const Egg* _eggs, unsigned size){
        delete[] eggs;
        eggs = new(std::nothrow) Egg[size];

        for (unsigned i = 0; i < size; ++i)
            eggs[i] = _eggs[i];
        capacity = numberOfEggs = size;
    }

    const char* getOwner() const { return owner; }
    const Egg* getEggs() const { return eggs; }
    unsigned getNumberOfEggs() const { return numberOfEggs; }

    bool addEgg(const Egg& egg){
        if(numberOfEggs >= capacity){
            resize(2*capacity);
        } 
        eggs[numberOfEggs] = egg;
        ++numberOfEggs;
    }

    bool removeEgg(const char* name){
        int index = -1;
        for(int i = 0; i<numberOfEggs; ++i){
            if(!strcmp(eggs[i].getName(), name))
                index = i;
        }
        if(index == -1)
            return false;

        eggs[index] = eggs[numberOfEggs - 1];
        --numberOfEggs;

        if(capacity >= 2* numberOfEggs){
            resize(2*numberOfEggs);
        }
        return true;
    }

    bool serialize(const char* filename){
        std::ofstream out(filename, std::ios::binary);
        if(!out.good())
            return false;
        unsigned len = strlen(owner);
        out.write((const char*)&len, sizeof(len));
        out.write(owner, len);
        out.write((const char*)&numberOfEggs, sizeof(numberOfEggs));
        for(int i=0; i < numberOfEggs; ++i){
            unsigned nameLength = strlen(eggs[i].getName());
            out.write((const char*)&nameLength, sizeof(nameLength));
            out.write(eggs[i].getName(), nameLength);

            unsigned size = eggs[i].getSize();
            out.write((const char*)&size, sizeof(size));
        }
        out.close();
        return true;
    }
    bool report(){
        const char* prefix = "report_";
        const char* suffix = ".txt";
        unsigned size = strlen(prefix) + strlen(owner) + strlen(suffix);
        char* fileName = new (std::nothrow) char[size+1];
        strcpy(fileName, prefix);
        strcat(fileName + strlen(prefix), owner);
        strcat(fileName + strlen(prefix) + strlen(owner), suffix);

        std::ofstream out(fileName);
        if(!out.good())
            return false;
        out << owner << std::endl;
        for(int i=0 ; i<numberOfEggs; ++i){
            out << eggs[i].getName() << "\t" << eggs[i].getSize() << std::endl;
        }
        out.close();
        return true;
    }
private:
    void resize(unsigned newCapacity){
        Egg* newEggs = new (std::nothrow) Egg[newCapacity];
        for(int i = 0 ; i<numberOfEggs; ++i)
            newEggs[i] = eggs[i];
        delete[] eggs;
        eggs = newEggs;
        capacity = newCapacity;
    }
private:
    char* owner;
    Egg* eggs;
    unsigned numberOfEggs;
    unsigned capacity;
};

int main() {
    return 0;
}