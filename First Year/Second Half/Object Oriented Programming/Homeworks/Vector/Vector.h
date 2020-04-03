//
// Created by Stephan Stephanov on 4/3/2020.
//

#ifndef __VECTOR_H
#define __VECTOR_H

template <typename T>
class Vector {
public:
    Vector();
    Vector(T*, unsigned);
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
    void shift(const T&);
    T unshift();

    void insert(const int&, const T&);
    void erase_all();
    void index_swap(const int&, const int&);


    void print();
private:
    T* data;
    unsigned size;

    void del_memory();
    void copy_memory(T*, unsigned);
};

#endif //!__VECTOR_H
