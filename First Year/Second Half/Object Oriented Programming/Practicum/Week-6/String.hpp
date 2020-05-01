#ifndef STRING_HPP

#define STRING_HPP

#include <iostream>


class String
{
private:
    char* data;
    unsigned capacity;

    char * copy_memory(const char*);
    void erase_mem();
    void enlarge_str();

public:
    String();
    String(const char*);
    String(const String&);
    ~String();

    String& operator=(const String&);
    
    unsigned get_length()const;
    unsigned get_capacity()const;

    String& append(const String&);
    String& append(const char*);

    bool empty() const;
    void erase();

    friend std::ostream& operator<<(std::ostream&, const String&);
};




#endif //!STRING_HPP