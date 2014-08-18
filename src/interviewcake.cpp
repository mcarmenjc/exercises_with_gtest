#include "../include/interviewcake.h"

double get_max_profit(double * stock_prices_yesterday, int length)
{
	double min_value = stock_prices_yesterday[0];
	double max_profit = 0;

	for (int i = 1; i < length; i++)
	{
		if (min_value > stock_prices_yesterday[i])
			min_value = stock_prices_yesterday[i];
		if (max_profit < (stock_prices_yesterday[i] - min_value))
			max_profit = stock_prices_yesterday[i] - min_value;
	}

	return max_profit;
}

bool is_openning_parentheses(char current_char)
{
	if (current_char == '(' || current_char == '{' || current_char == '[')
		return true;
	return false;
}

bool are_same_type_of_parentheses(char current_char, char poped_char)
{
	if ((current_char == ')' && poped_char == '(') &&
		(current_char == '}' && poped_char == '{') &&
		(current_char == ']' && poped_char == '[') )
		return true;
	return false;
}

bool parentheses_validator(std::string string_to_validate)
{
	std::stack<char> openning_stack;

	for (int i = 0; i < string_to_validate.length(); i++)
	{
		if (is_openning_parentheses(string_to_validate[i]))
		{
			openning_stack.push(string_to_validate[i]);
		}
		else
		{
			if (openning_stack.empty())
				return false;
			char poped_char = openning_stack.top();
			openning_stack.pop();
			if (!are_same_type_of_parentheses(string_to_validate[i], poped_char))
				return false;
		}
	}

	if (!openning_stack.empty())
		return false;
	return true;
}

void reverse_array(int * array, int length)
{
	for (int i = 0, j < length-1; i < j; i++, j--)
	{
		int aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
}
