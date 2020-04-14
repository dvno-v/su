#ifndef TRIANGLE_H

#define TRIANGLE_H
#include <iostream>


template <typename T>
class Triangle
{
public:
	Triangle(const Triangle&);
	Triangle(const T&, unsigned);
	Triangle& operator=(const Triangle&);
	~Triangle();

	void increment_rows();
	unsigned get_rows() const;
	T& get_at(unsigned, unsigned) const;
	bool is_symetric() const;
	void print();
	template <typename U>
	friend std::istream& operator>>(std::istream&, Triangle<U>&);


private:
	T** data;
	unsigned curr_number_rows;
	unsigned max_rows;

	void copy_object(const Triangle&);
	void del_memory();
};

template <typename T>
void Triangle<T>::copy_object(const Triangle& _other) {
	this->data = new T * [_other.max_rows];
	for (unsigned i = 0; i < _other.curr_number_rows; i++)
	{
		this->data[i] = new T[i + 1];
		for (unsigned k = 0; k < i; k++)
		{
			this->data[i][k] = _other.data[i][k];
		}
	}
	this->max_rows = _other.max_rows;
	this->curr_number_rows = _other.curr_number_rows;
}

template <typename T>
void Triangle<T>::del_memory() {
	for (unsigned i = 0; i < this->curr_number_rows; i++)
	{
		delete[] this->data[i];
	}
	delete[] this->data;
}

template <typename T>
Triangle<T>::Triangle(const T& _el, unsigned _max_rows)
{
	this->max_rows = _max_rows;
	this->curr_number_rows = 1;
	this->data = new T * [_max_rows];
	this->data[0] = new T(_el);
}

template <typename T>
Triangle<T>::Triangle(const Triangle& _other)
{
	this->del_memory();
	this->copy_object(_other);
}

template <typename T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T>& _other)
{
	if (this != &_other) {
		this->del_memory();
		this->copy_object(_other);
	}
	return *this;

}

template <typename T>
Triangle<T>::~Triangle()
{
	this->del_memory();
}

template<typename T>
inline unsigned Triangle<T>::get_rows() const
{
	return this->curr_number_rows;
}

template<typename T>
T& Triangle<T>::get_at(unsigned i, unsigned k) const
{
	if(i < this->get_rows() && k < this->get_rows() && i >= 0 && k >= 0)
		return this->data[i][k];
	return this->data[0][0];
}

template<typename T>
bool Triangle<T>::is_symetric() const {
	for (unsigned i = 0; i < this->curr_number_rows; i++)
	{
		unsigned half = this->curr_number_rows / 2;
		for (unsigned k = 0; k < half; k++)
		{
			if (data[i][k] != data[i][this->curr_number_rows - k - 1]) return false;
		}
	}
	return true;
}

template<typename T>
void Triangle<T>::print()
{
	for (unsigned i = 0; i < this->curr_number_rows; i++)
	{
		for (unsigned k = 0; k <= i; k++)
		{
			std::cout << this->data[i][k] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
void Triangle<T>::increment_rows() {
	++(this->curr_number_rows);
}

template <typename U>
std::istream& operator>>(std::istream& in, Triangle<U>& t)
{
	if (t.curr_number_rows + 1 > t.max_rows) {
		std::cout << "Not enough space\n";
		return in;
	}
	t.data[t.curr_number_rows] = new U[t.curr_number_rows + 1];
	for (unsigned k = 0; k <= t.curr_number_rows; k++)
	{
		in >> t.data[t.curr_number_rows][k];
	}
	t.increment_rows();
	return in;
}


#endif // TRIANGLE_H
