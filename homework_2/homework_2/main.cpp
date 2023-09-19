#include "function.h"
#include <iostream>

int main() {
	std::cout << "Create vector a" << '\n';
	TVector a;

	TVector b;

	a.fillVector();
	std::cout << "Vector a = " << a;
	b.fillVector();
	std::cout << "Vector b = " << b;

	TVector c = a + b;
	std::cout << "a + b = " << c;

	c -= a;
	std::cout << "c == a ? Maybe : " << (c==a) << '\n';
	std::cout << "c == b ? Maybe : " << (c==b) << '\n';

	// Check length, scalarProduct and cosDistance
	std::cout << "Length of a = " << a.length() << "\n";
	std::cout << "Length of b = " << b.length() << "\n";


	std::cout << "a scalar * b = " << a.scalarProduct(b) << '\n';
	std::cout << "cosDist(a, b) = " << a.cosDistance(b) << '\n';
	return 0;
}