#include "function.h"
#include "math.h"
#include <iostream>
#include <istream>

//constructors:
TVector::TVector ()
{
	n = 0;
	x = NULL;
}

TVector::TVector(const TVector& vector)
{
	n = vector.n;
	x = new float[n];
	for (int i = 0; i < n; ++i) {
		x[i] = vector.x[i];
	}
}

//fucntions
void TVector::fillVector() {
	std::cout << "Enter vector dimension \n";
	std::cin >> n;
	x = new float[n];
	std::cout << "Enter vector coordinates \n";
	for (int i = 0; i < n; i++)
	{
		std::cin >> x[i];
	}
}


TVector TVector::operator+(const TVector& vector) //покомпонентное сложение
{
	try {

		if (n != vector.n) {
			throw "Cannot accumulate vectors with different dimensions!";
		}
		TVector c(vector);
		for (int i = 0; i < n; i++)
		{
			c.x[i] += x[i];
		}
		return c;
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}

TVector TVector::operator-(const TVector& vector) // покомпонентное вычитание
{
	try {

		if (n != vector.n) {
			throw "Cannot subtract vectors with different dimensions!";
		}
		TVector c(*this);
		for (int i = 0; i < n; i++)
		{
			c.x[i] -= vector.x[i];
		}
		return c;
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}
TVector TVector::operator*(const TVector& vector) {
	try {

		if (n != vector.n) {
			throw "Cannot multiply vectors with different dimensions!";
		}
		TVector c(*this);
		for (int i = 0; i < n; i++)
		{
			c.x[i] *= vector.x[i];
		}
		return c;
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}

TVector& TVector::operator=(const TVector& vector) {
	if ((*this) == vector) {
		return *this;
	}
	if (n != vector.n) {
		delete[]x;
		x = new float[vector.n];
		n = vector.n;
	}
	for (int i = 0; i < n; ++i) {
		x[i] = vector.x[i];
	}
	return *this;
}

bool TVector::operator==(const TVector& vector) {
	if (n != vector.n) {
		return false;
	}

	for (int i = 0; i < n; ++i) {
		if (x[i] != vector.x[i]) {
			return false;
		}
	}

	return true;
}

bool TVector::operator!=(const TVector& vector) {
	return !((*this) == vector);
}

TVector& TVector::operator-=(const TVector& vector) {
	try {

		if (n != vector.n) {
			throw "Cannot subtract vectors with different dimensions!";
		}
		for (int i = 0; i < n; i++)
		{
			x[i] -= vector.x[i];
		}
		return (*this);
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}

TVector& TVector::operator*=(const TVector& vector) {
	try {

		if (n != vector.n) {
			throw "Cannot multiply vectors with different dimensions!";
		}
		for (int i = 0; i < n; i++)
		{
			x[i] *= vector.x[i];
		}
		return (*this);
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}
TVector& TVector::operator+=(const TVector& vector) {
	try {

		if (n != vector.n) {
			throw "Cannot accumulate vectors with different dimensions!";
		}
		for (int i = 0; i < n; i++)
		{
			x[i] += vector.x[i];
		}
		return (*this);
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}

std::ostream& operator<<(std::ostream& out, const TVector& v) {
	out << "( ";
	for (int i = 0; i < v.n; ++i) {
		out << v.x[i] << " ";
	}
	out << ")" << '\n';
	return out;
}

std::istream& operator>>(std::ifstream& in, TVector& v) {
	in >> v.n;
	for (int i = 0; i < v.n; i++)
	{
		in >> v.x[i];
	}
	return in;
}

float TVector::length() const {
	float sum = 0.f;
	for (int i = 0; i < n; ++i) {
		sum += (x[i] * x[i]);
	}
	return std::sqrt(sum);
}

float TVector::scalarProduct(const TVector& vector) {
	try {

		if (n != vector.n) {
			throw "Cannot scalar multiply vectors with different dimensions!";
		}
		float sum = 0.f;
		for (int i = 0; i < n; i++)
		{
			sum += x[i] * vector.x[i];
		}
		return sum;
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}

float TVector::cosDistance(const TVector& vector) {
	try {

		if (n != vector.n) {
			throw "Cannot find cos distance vectors with different dimensions!";
		}
		float sum = scalarProduct(vector);
		float del = length() * vector.length();
		return (sum / del);
	}
	catch (const char* ex) {
		std::cout << ex;
		exit(1);
	}
}