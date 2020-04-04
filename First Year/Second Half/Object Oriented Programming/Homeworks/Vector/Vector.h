//
// Created by Stephan Stephanov on 4/3/2020.
//

#ifndef __VECTOR_H
#define __VECTOR_H

template <typename T>
class Vector {
public:
    Vector();
    Vector(T*, const unsigned&);
    Vector(const Vector&);
    ~Vector();

    T* get_data();
    unsigned get_size();

    T* beggining();
    T* end();

    bool is_empty();

    T&operator[](const int&);
    T& at(const int&);

    void assign(const int&, const T&);
    void assign(const T*, const T*);

    void push(const T&);
    T pop();
    void unshift(const T&);
    T shift();

    void insert(const int&, const T&);
    void erase_all();
    void index_swap(const int&, const int&);

    Vector&operator=(const Vector&);

    void print();
private:
    T* data;
    unsigned size;

    void del_memory();
    void copy_memory(const T*, const unsigned&);
    T* copy_and_resize(const T*,const unsigned&, const unsigned&);
};

#endif //!__VECTOR_H
