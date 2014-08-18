#include "../include/matrix2by2.h"

Matrix2By2::Matrix2By2()
{
	m00 = 0;
	m01 = 0;
	m10 = 0;
	m11 = 0;
}

Matrix2By2::Matrix2By2(long pos00, long pos01, long pos10, long pos11)
{
	m00 = pos00;
	m01 = pos01;
	m10 = pos10;
	m11 = pos11;
}

Matrix2By2::Matrix2By2(const Matrix2By2 &matrix)
{
	m00 = matrix.m00;
	m01 = matrix.m01;
	m10 = matrix.m10;
	m11 = matrix.m11;
}

long Matrix2By2::get_m00()
{
	return m00;
}

long Matrix2By2::get_m01()
{
	return m01;
}

long Matrix2By2::get_m10()
{
	return m10;
}

long Matrix2By2::get_m11()
{
	return m11;
}

void Matrix2By2::set_m00(long value)
{
	m00 = value;
}

void Matrix2By2::set_m01(long value)
{
	m01 = value;
}

void Matrix2By2::set_m10(long value)
{
	m10 = value;
}

void Matrix2By2::set_m11(long value)
{
	m11 = value;
}

Matrix2By2 Matrix2By2::multiplication(const Matrix2By2 & matrix)
{
	Matrix2By2 result;
	result.m00 = m00*matrix.m00 + m01*matrix.m10;
	result.m01 = m00*matrix.m01 + m01*matrix.m11;
	result.m10 = m10*matrix.m00 + m11*matrix.m10;
	result.m11 = m10*matrix.m01 + m11*matrix.m11;

	return result;
}

Matrix2By2 Matrix2By2::pow(int n)
{
	Matrix2By2 base_case = Matrix2By2(m00, m01, m10, m11);
	Matrix2By2 result;
	if (n == 1)
		return base_case;

	if (n%2 == 0)
	{
		result = pow(n/2);
		result = result.multiplication(result);
	}

	else
	{
		result = pow((n-1)/2);
		result = result.multiplication(result);
		result = result.multiplication(base_case);
	}

	return result;
}