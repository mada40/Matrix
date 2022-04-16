#include <cmath>
#include <iostream>
#pragma once
class MyVector
{
		double* data = nullptr;
		int N = 0;

	public:
		MyVector();
		MyVector(int N);
		~MyVector();
		MyVector(const MyVector& other);

		int size() const
		{
			return N;
		}
		void resize(int newSize);

		double& operator[] (int i)
		{
			return data[i];
		}
		double operator[] (int i) const
		{
			return data[i];
		}

		MyVector operator + (const MyVector& other) const;
		MyVector operator - (const MyVector& other) const;
		MyVector& operator = (const MyVector& other);
		MyVector& operator += (const MyVector& other);
		MyVector& operator -= (const MyVector& other);

		MyVector operator * (double other) const;
		MyVector& operator *= (double other);

		double dot(const MyVector& other) const;

		double getNorm()  const
		{
			return sqrt(dot(*this));
		}

		friend std::ostream& operator<<(std::ostream& out, const MyVector& v);
		
};

