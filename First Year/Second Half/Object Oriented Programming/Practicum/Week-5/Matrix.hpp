#ifndef MATRIX_HPP

#define MATRIX_HPP
#include <iostream>
#include <assert.h>

template <typename T>
class Matrix {
public:
	Matrix();
	Matrix(unsigned, unsigned);
	Matrix(const T**, unsigned, unsigned);
	Matrix(const Matrix&);
	~Matrix();
	Matrix& operator=(const Matrix&);

	void set_el(unsigned, unsigned, T);
	Matrix* operator+(const Matrix&);
	Matrix* operator*(const Matrix&);
	void print();

private:
	T** data;
	unsigned rows;
	unsigned cols;
	void del_memory();
	void copy_memory(T**, unsigned, unsigned);
};
template <typename T>
void Matrix<T>::del_memory() {
	for (unsigned i = 0; i < this->rows; i++)
	{
		delete[] this->data[i];
	}
	delete[] this->data;
}
template <typename T>
void Matrix<T>::copy_memory(T** _data, unsigned _rows, unsigned _cols) {
	this->del_memory();
	this->data = new T * [_rows];
	for (unsigned i = 0; i < _rows; i++)
	{
		this->data[i] = new T[_cols];
		if (_data != nullptr) {
			for (unsigned k = 0; k < _cols; k++)
			{
				this->data[i][k] = _data[i][k];
			}
		}
		else {
			for (unsigned k = 0; k < _cols; k++)
			{
				this->data[i][k] = 0;
			}
		}
	}
	this->rows = _rows;
	this->cols = _cols;
}


template <typename T>
Matrix<T>::Matrix() {
	this->data = nullptr;
	this->rows = 0;
	this->cols = 0;
}

template <typename T>
Matrix<T>::Matrix(unsigned _rows, unsigned _cols) {
	this->copy_memory(nullptr, _rows, _cols);
}

template <typename T>
Matrix<T>::Matrix(const T** _data, unsigned _rows, unsigned _cols){
	this->copy_memory(_data, _rows, _cols);
}

template <typename T>
Matrix<T>::Matrix(const Matrix& _other){
	this->copy_memory(_other.data, _other.rows, _other.cols);
}

template <typename T>
Matrix<T>::~Matrix() {
	this->del_memory();
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& _other){
	if(this != &_other)
		this->copy_memory(_other.data, _other.rows, _other.cols);
	
	return *this;
}

template <typename T>
void Matrix<T>::set_el(unsigned _row, unsigned _col, T el){
	assert(_row < this->rows);
	assert(_col < this->cols);
	this->data[_row][_col] = el;
}

template <typename T>
Matrix<T>* Matrix<T>::operator+(const Matrix& _other){
	assert(this->cols == _other.cols);
	assert(this->rows == _other.rows);
	Matrix* temp= new Matrix<T>(*this);
	for (unsigned i = 0; i < this->rows; i++)
	{
		for (unsigned k = 0; k < _other.cols; k++)
		{
			temp->data[i][k] += _other.data[i][k];
		}
	}
	return temp;
}

template <typename T>
Matrix<T>* Matrix<T>::operator*(const Matrix& _other){
	assert(this->cols == _other.rows);
	Matrix* temp = new Matrix<T>(this->rows, _other.cols);
	for (unsigned i = 0; i < this->rows; i++)
	{
		for (unsigned k = 0; k < _other.cols; k++)
		{
			for (unsigned j = 0; j < this->cols; j++)
			{
				temp->data[i][k] += this->data[i][j] * _other.data[j][k];
			}
		}
	}
	return temp;
}

template <typename T>
void Matrix<T>::print() {
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned k = 0; k < cols; k++)
		{
			std::cout << data[i][k] << "  ";
		}
		std::cout << std::endl;
	}
}


#endif // !MATRIX_HPP
