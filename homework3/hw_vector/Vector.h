#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <istream>
#include <fstream>

template <class T> class Vector {
private:
	T* vec;
	int size;
public:
	Vector();
	Vector(int size);
	Vector(const Vector <T>& obj);
	
	~Vector();
	
	Vector <T> operator+(const Vector<T>& obj);
	Vector <T> operator-(const Vector<T>& obj);

	double operator*(const Vector<T>& obj) const;
	double length() const;

	void fillVector();

	bool operator==(const Vector<T>& obj) const;
	bool operator!=(const Vector<T>& obj) const;

	const Vector <T>& operator=(const Vector<T>& obj);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const Vector <T>& obj);
	template<typename T>
	friend std::istream& operator>>(std::ifstream& in, Vector <T>& obj);
};

//constructors:
template <typename T>
Vector <T> ::Vector()
{
	size = 0;
	vec = NULL;
}

template <typename T>
Vector <T> ::Vector(const Vector <T>& obj)
{
	size = obj.size;
	vec = new T[size];
	for (int i = 0; i < size; i++)
	{
		vec[i] = obj.vec[i];
	}
}

template <typename T>
Vector <T> ::Vector(int size)
{
	this->size->size;
}

//distruct
template <typename T>
Vector <T> ::~Vector()
{
	if (size >= 0)
	{
		delete[]vec;
		size = 0;
	}
}

//operators
// //out 
template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& obj)
{
	out << "( ";
	for (int i = 0; i < obj.size; ++i) {
		out << obj.vec[i] << " ";
	}
	out << ")" << '\n';
	return out;

}
//in
template <typename T>
std::istream& operator>>(std::ifstream& in, Vector<T>& obj)
{
	in >> obj.size;
	for (int i = 0; i < obj.size; i++)
	{
		in >> obj.vec[i];
	}
	return in;
}
//+
template <typename T>
Vector <T> Vector <T>::operator+(const Vector<T>& obj)
{
	try {

		if (size != obj.size) {
			throw "Cannot accumulate vectors with different dimensions!";
		}
		Vector <T> c(*this);
		for (int i = 0; i < size; i++)
		{
			c.vec[i] += obj.vec[i];
		}
		return c;
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}
//-
template <typename T>
Vector <T> Vector <T>::operator-(const Vector<T>& obj)
{
	try {

		if (size != obj.size) {
			throw "Cannot subtract vectors with different dimensions!";
		}
		Vector <T> c(*this);
		for (int i = 0; i < size; i++)
		{
			c.vec[i] -= obj.vec[i];
		}
		return c;
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}
//*
template <typename T>
double Vector <T>:: operator*(const Vector<T>& obj) const
{
	try {

		if (size != obj.size) {
			throw "Cannot scalar multiply vectors with different dimensions!";
		}
		double sum = 0.0;
		for (int i = 0; i < size; i++)
		{
			sum += vec[i] * obj.vec[i];
		}
		return (sum);
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}
// =
template <typename T>
const Vector <T>& Vector <T>::operator=(const Vector<T>& obj)
{
	if (this == &(obj))
	{
		return (*this);
	}
	if (size != obj.size)
	{
		delete[]vec;
		size = obj.size;
	}
	for (int i = 0; i < size; i++)
	{
		vec[i] = obj.vec[i];
	}
	return (*this);
}
//==
template <typename T>
bool Vector <T> ::operator==(const Vector<T>& obj) const 
{
	if (size != obj.size) {
		return false;
	}

	for (int i = 0; i < size; ++i) {
		if (vec[i] != obj.vec[i]) {
			return false;
		}
	}

	return true;
}
//!=
template <typename T>
bool Vector <T> ::operator!=(const Vector<T>& obj) const
{
	return !((*this) == obj);
}

//functions
template <typename T>
double Vector <T>::length() const
{
	double sum = 0.0;
	for (int i = 0; i <size; ++i) {
		sum += (vec[i] * vec[i]);
	}
	return std::sqrt(sum);
}

template <typename T>
void Vector <T>::fillVector()
{
	std::cout << "Enter vector dimension \n";
	std::cin >> size;
	vec = new float[size];
	std::cout << "Enter vector coordinates \n";
	for (int i = 0; i < size; i++)
	{
		std::cin >> vec[i];
	}
}
#endif
