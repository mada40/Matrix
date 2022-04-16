#pragma once
#include "Vector.h"
#include <iostream>
class Matrix
{
private:
	MyVector* lines = nullptr;
	int N = 0;	//количество строк
	int M = 0;	//количество столбцов

public:

	~Matrix() { delete[] lines; }
	MyVector& operator[](int i) { return lines[i]; }
	MyVector operator[](int i) const { return lines[i]; }

	Matrix();
	Matrix(int n, int m);
	Matrix(const Matrix& other);

	Matrix& operator = (const Matrix& other);
	Matrix& operator -= (const Matrix& other);
	Matrix& operator += (const Matrix& other);
	Matrix& operator *= (const Matrix& other);
	Matrix& operator *= (double c);

	Matrix operator - () const;
	Matrix operator + (const Matrix& other) const;
	Matrix operator - (const Matrix& other) const;
	Matrix operator * (const Matrix& other) const;
	Matrix operator * (double c) const;

	bool operator == (const Matrix& other) const;
	bool operator != (const Matrix& other) const;


	friend std::ostream& operator<<(std::ostream& out, const Matrix& v);

};

