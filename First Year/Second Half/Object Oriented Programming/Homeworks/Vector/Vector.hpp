//
// Created by Stephan Stephanov on 4/3/2020.
//

#ifndef __VECTOR_HPP

#define __VECTOR_HPP

#include <iostream>
#include <algorithm>


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


template <typename T>
void Vector<T>::del_memory() {
    delete[] this->data;
    //std::cout << "Deleting memory\n";
}

template <typename T>
void Vector<T>::copy_memory(const T*_data, const unsigned& _data_size) {
    this->del_memory();
    this->data = new T[_data_size];

    for (unsigned i = 0; i < _data_size; ++i) {
        this->data[i] = _data[i];
    }
}

template<typename T>
T *Vector<T>::copy_and_resize(const T* _source, const unsigned& new_size, const unsigned& old_size) {
    T* temp = new T[new_size];
    for (int i = 0; i < std::min(new_size, old_size) ; ++i) {
        temp[i] = _source[i];
    }
    return temp;
}

template <typename T>
Vector<T>::Vector() {
    this->data = nullptr;
    this->size = 0;
}

template <typename T>
Vector<T>::Vector(T* _data, const unsigned& _data_size) {
    this->copy_memory(_data, _data_size);
    this->size = _data_size;
}

template <typename T>
Vector<T>::Vector(const Vector & _other) {
    this->copy_memory(_other.data, _other.size);
    this->size = _other.size;
}


template <typename T>
Vector<T>::~Vector() {
    this->del_memory();
    std::cout << "in destructor ofc\n";
}

template <typename T>
void Vector<T>::print() {
    if(this->data != nullptr) {
        for (int i = 0; i < this->size; ++i) {
            std::cout << this->data[i] << " ";
        }
        std::cout << '\n';
    }
    else{
        std::cout << "Empty\n";
    }
}

template<typename T>
T *Vector<T>::get_data() {
    return this->data;
}

template<typename T>
unsigned Vector<T>::get_size() {
    return this->size;
}

template<typename T>
T *Vector<T>::beggining() {
    return this->data;
}

template<typename T>
T *Vector<T>::end() {
    return (this->data + this->size - 1);
}

template<typename T>
bool Vector<T>::is_empty() {
    return this->size == 0;
}

template<typename T>
T &Vector<T>::operator[](const int & index) {
    return this->data[index];
}

template<typename T>
T &Vector<T>::at(const int&index) {
    return (*this)[index];
}

template<typename T>
void Vector<T>::assign(const int & amount, const T & value) {
    this->del_memory();
    this->data = new T[amount];
    for (int i = 0; i < amount; ++i) {
        this->data[i] = value;
    }
    this->size = amount;
}

template<typename T>
void Vector<T>::assign(const T * start ,const T * end) {
    unsigned amount = end - start;
    this->del_memory();
    this->data = new T[amount];
    for (int i = 0; i < amount; ++i) {
        this->data[i] = *(start + i);
    }
    this->size = amount;
}

template<typename T>
void Vector<T>::push(const T & new_el) {
    T*temp = this->copy_and_resize(this->data, this->size + 1, this->size);
    temp[this->size] = new_el;
    this->del_memory();
    this->data = temp;
    ++(this->size);
}

template<typename T>
T Vector<T>::pop() {
    T return_value = *(this->end());
    T*temp = this->copy_and_resize(this->data, this->size - 1, this->size);
    this->del_memory();
    this->data = temp;
    --(this->size);
    return return_value;
}

template<typename T>
void Vector<T>::unshift(const T &new_el) {
    std::reverse(this->data, this->data + this->size);
    this->push(new_el);
    std::reverse(this->data, this->data + this->size);
}

template<typename T>
T Vector<T>::shift() {
    T temp = data[0];
    std::reverse(this->data, this->data + this->size);
    this->pop();
    std::reverse(this->data, this->data + this->size);
    return temp;
}

template<typename T>
void Vector<T>::insert(const int & index, const T & new_el) {
    T *temp = new T[this->size + 1];
    bool has_passed_index = false;
    for (int i = 0; i < this->size + 1; ++i) {
        if (has_passed_index) {
            temp[i] = data[i - 1];
        }else if(index == i){
            temp[index] = new_el;
            has_passed_index = true;
        }
        else {
            temp[i] = data[i];
        }
    }
    this->del_memory();
    this->data = temp;
    ++(this->size);
}

template<typename T>
void Vector<T>::erase_all() {
    this->del_memory();
    this->data = new T[this->size];
}

template<typename T>
void Vector<T>::index_swap(const int &index1, const int &index2) {
    std::swap((*this)[index1], (*this)[index2]);
}

template<typename T>
Vector<T>&Vector<T>::operator=(const Vector & _other) {
    this->copy_memory(_other.data, _other.size);
    this->size = _other.size;
    return *this;
}



#endif //!__VECTOR_HPP
