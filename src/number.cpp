#include "../include/number.h"

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
