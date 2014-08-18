#include "../include/number.h"
#include "../include/matrix2by2.h"

Number::Number(long number)
{
	no = number;
}

bool Number::is_palindrome()
{
	long reversed_number = reverse_number();
	if (reversed_number == no)
		return true;
	return false;
}

long Number::reverse_number()
{
	long aux_number = no;
	long reversed_number = 0;
	while (aux_number != 0)
	{
		reversed_number = reversed_number*10 + aux_number%10;
		aux_number = aux_number/10;
	}
	return reversed_number;
}

long Number::fibonacci_recursive()
{
	return fibonacci_recursive_core(no);
}

long Number::fibonacci_recursive_core(long actual_n)
{
	if (actual_n <= 0)
		return 0;
	if (actual_n == 1)
		return 1;
	return fibonacci_recursive_core(actual_n - 1) + fibonacci_recursive_core(actual_n - 2);
}

long Number::fibonacci_iterative()
{
	if (no == 0)
		return 0;
	if (no == 1)
		return 1;

	long fibonacci_n_2 = 0;
	long fibonacci_n_1 = 1;
	long fibonacci_n;

	for (long i = 2; i <= no; i++)
	{
		fibonacci_n = fibonacci_n_1 + fibonacci_n_2;
		fibonacci_n_2 = fibonacci_n_1;
		fibonacci_n_1 = fibonacci_n;
	}

	return fibonacci_n;
}

long Number::fibonacci_using_matrix()
{
	if (no == 0)
		return 0;
	if (no == 1)
		return 1;

	Matrix2By2 base_case = Matrix2By2(1, 1, 1, 0);
	Matrix2By2 result = base_case.pow(no-1);
	return result.get_m00();
}