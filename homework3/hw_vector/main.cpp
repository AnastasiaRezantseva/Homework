#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <iostream>



int main()
{
	std::cout << "Create vector a" << '\n';
	Vector <float> a;

	Vector <float> b;

	a.fillVector();
	std::cout << "Vector a = " << a;
	b.fillVector();
	std::cout << "Vector b = " << b;

	Vector <float> c = a + b;

	std::cout << "a + b = " << c;
	c = a - b;
	std::cout << "a - b = " << c;

	// Check length, scalarProduct 
	std::cout << "Length of a = " << a.length() << "\n";
	std::cout << "Length of b = " << b.length() << "\n";
	std::cout << "a scalar * b = " << a * b << '\n';
	return 0;
}