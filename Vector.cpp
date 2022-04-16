#include "Vector.h"
#include <iostream>

	MyVector::MyVector()
	{
		data = nullptr;
		N = 0;	
	}
	MyVector::MyVector(int n)
	{
		N = n;
		data = new double[N];
		for (int i = 0; i < N; i++)
		{
			data[i] = 0.0;
		}
	}
	MyVector::~MyVector()
	{
		delete[] data;
	}

	

	void MyVector::resize(int newSize)
	{
		double* olddata = new double[newSize];
		int minSize = std::min(N, newSize);

		for (int i = 0; i < minSize; i++)
		{
			olddata[i] = data[i];
		}

		delete[] data;
		data = olddata;

		for (int i = minSize; i < newSize; i++)
		{
			data[i] = 0.0;
		}

		N = newSize;
		
	}

	MyVector MyVector::operator + (const MyVector& other) const
	{
		if (other.N != N) throw "ERROR";

		MyVector ans(N);

		for (int i = 0; i < N; i++)
		{
			ans[i] = data[i] + other[i];
		}
		return ans;
	}
	MyVector MyVector::operator - (const MyVector& other) const
	{
		if (other.N != N) throw "ERROR";

		MyVector ans(N);

		for (int i = 0; i < N; i++)
		{
			ans[i] = data[i] - other[i];
		}
		return ans;
	}

	MyVector MyVector::operator * (double c) const
	{
		MyVector ans(N);
		for (int i = 0; i < N; i++)
		{
			ans[i] = data[i] * c;
		}
		return ans;
	}

	MyVector& MyVector::operator *= (double c)
	{
		for (int i = 0; i < N; i++)
		{
			data[i] *= c;
		}
		return *this;
	}

	MyVector::MyVector(const MyVector& other)
	{
		resize(other.N);

		for (int i = 0; i < N; i++)
		{
			data[i] = other[i];
		}
	}

	MyVector& MyVector::operator=(const MyVector& other)
	{
		resize(other.N);
		for (int i = 0; i < N; i++)
		{
			data[i] = other[i];
		}
		return *this;
	}

	MyVector& MyVector::operator+=(const MyVector& other)
	{
		if (other.N != N) throw "ERROR";
		for (int i = 0; i < N; i++)
		{
			data[i] += other[i];
		}
		return *this;
	}

	MyVector& MyVector::operator-=(const MyVector& other)
	{
		if (other.N != N) throw "ERROR";
		for (int i = 0; i < N; i++)
		{
			data[i] -= other[i];
		}
		return *this;
	}


	double MyVector::dot(const MyVector& other)	const
	{
		double ans = .0;
		for (size_t i = 0; i < N; i++)
		{
			ans += other[i] * data[i];
		}
		return ans;
	}

	std::ostream& operator<<(std::ostream& out, const MyVector& v)
	{
		out << "{ ";
		for (int i = 0; i < v.N; i++)
		{
			std::cout << v.data[i] << " ";
		}
		out << "}";
		return out;
	}



