//
// Created by Stephan Stephanov on 4/3/2020.
//
#ifndef __VECTOR_CPP

#define __VECTOR_CPP

#include <iostream>
#include <algorithm>
#include "Vector.h"

template <typename T>
void Vector<T>::del_memory() {
    delete[] this->data;
    std::cout << "Deleting memory\n";
}

template <typename T>
void Vector<T>::copy_memory(T*_data, unsigned _data_size) {
    this->del_memory();
    this->data = new T[_data_size];

    for (unsigned i = 0; i < _data_size; ++i) {
        this->data[i] = _data[i];
    }
}

template <typename T>
Vector<T>::Vector() {
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

template <typename T>
Vector<T>::Vector(T* _data, unsigned _data_size) {
    this->copy_memory(_data, _data_size);
    this->size = _data_size;
    this->capacity = 2*_data_size;
}

template <typename T>
Vector<T>::Vector(const Vector & _other) {
    this->copy_memory(_other.data, _other.size);
    this->size = _other.size;
    this->capacity = _other.capacity;
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
    }
    else{
        std::cout << "Empty\n";
    }
    std::cout << '\n';
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
unsigned Vector<T>::get_capacity() {
    return this->capacity;
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
    this->capacity = 2 * amount;
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
    this->capacity = amount * 2;
}

template<typename T>
void Vector<T>::push(const T & new_el) {
   if(this->size >= this->capacity){
       this->capacity *= 2;
   }
    T* temp = new T[this->size + 1];
    for (int i = 0; i < this->size; ++i) {
        temp[i] = this->data[i];
    }
    temp[this->size] = new_el;
    this->del_memory();
    this->data = temp;
    ++this->size;
}

template<typename T>
T Vector<T>::pop() {
    T return_value = *(this->end());
    T* temp = new T[this->size - 1];
    for (int i = 0; i < this->size - 1; ++i) {
        temp[i] = data[i];
    }
    del_memory();
    data = temp;
    --size;
    return return_value;
}

template<typename T>
void Vector<T>::shift(const T &new_el) {
    std::reverse(this->data, this->data + this->size);
    this->push(new_el);
    std::reverse(this->data, this->data + this->size);
}

template<typename T>
T Vector<T>::unshift() {
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
    del_memory();
    data = temp;
    if(size >= capacity) capacity *= 2;
    ++size;
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

#endif // !__VECTOR_CPP