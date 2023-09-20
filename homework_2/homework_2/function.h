#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <fstream>
class TVector {
private:
	int n;
	float* x;
public:
	TVector();
	TVector( const TVector& vector);
	void fillVector();

	// operations
	TVector operator+(const TVector& vector);
	TVector operator-(const TVector& vector);
	float operator*(const TVector& vector);

	const TVector& operator=(const TVector& vector);
	bool operator==(const TVector& vector) const;
	bool operator!=(const TVector& vector) const;

	TVector& operator-=(const TVector& vector);
	TVector& operator+=(const TVector& vector);
	TVector& operator*=(const TVector& vector);

	//float scalarProduct(const TVector& vector);
	float cosDistance(const TVector& vector);

	float length() const;


	friend std::ostream& operator<<(std::ostream& out, const TVector& v);
	friend std::istream& operator>>(std::ifstream& in, TVector& v);
};

#endif
