#include "Matrix.h"

Matrix::Matrix()
{
	N = 0;
	M = 0;
	lines = nullptr;
}
Matrix::Matrix(int n, int m)
{
	N = n;
	M = m;
	lines = new MyVector[N];
	for (int i = 0; i < N; i++)
	{
		lines[i] = MyVector(M);
	}
}

Matrix::Matrix(const Matrix& other)
{
	delete[] lines;
	N = other.N;
	M = other.M;
	lines = new MyVector[N];
	for (int i = 0; i < N; i++)
	{
		lines[i] = other[i];
	}
}

Matrix& Matrix::operator=(const Matrix& other)
{
	delete[] lines;
	N = other.N;
	M = other.M;
	lines = new MyVector[N];
	for (int i = 0; i < N; i++)
	{
		lines[i] = other[i];
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (other.M != M || other.N != N) throw "ERROR";
	*this = *this - other;
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	if (other.M != M || other.N != N) throw "ERROR";
	*this = *this + other;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	if (M != other.N) throw "ERROR";
	*this = *this * other;
	return *this;
}

Matrix& Matrix::operator*=(double c)
{
	*this = *this * c;
	return *this;	
}

Matrix Matrix::operator-() const
{
	return *this * -1;
}

Matrix Matrix::operator + (const Matrix& other)	const
{
	if (other.M != M || other.N != N) throw "ERROR";
	Matrix ans(N, M);

	for (int i = 0; i < N; i++)
	{
		ans[i] = lines[i] + other[i];
	}
	return ans;
}

Matrix Matrix::operator - (const Matrix& other)	const
{
	if (other.M != M || other.N != N) throw "ERROR";
	return *this + (-other);
}

Matrix Matrix::operator*(const Matrix& other) const
{
	if (M != other.N) throw "ERROR";
	Matrix ans(N, other.M);
	for (int i = 0; i < ans.N; i++)
	{
		for (int j = 0; j < ans.M; j++)
		{
			for (int q = 0; q < N; q++)
			{
				ans[i][q] = lines[i][q] * other[q][i];
			}
		}
	}
	return ans;
}

Matrix Matrix::operator*(double c) const
{
	Matrix ans(N, M);

	for (int i = 0; i < N; i++)
	{
		ans[i] = lines[i] * c;
	}
	return ans;
}

bool Matrix::operator==(const Matrix& other) const
{
	if (N != other.N || M != other.M) return false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (abs(lines[i][j] != other[i][j])) return false;
		}
		
	}

	return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
	out << std::endl;
	for (int i = 0; i < m.N; i++)
	{
		for (int j = 0; j < m.M; j++)
		{
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return out;
}


