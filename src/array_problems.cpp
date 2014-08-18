#include "../include/array_problems.h"
#include <iostream>
#include <new>

int repeated_number(int * numbers_array, int size)
{
	int * counters = new int [size];

	for (int i = 0; i < size; i++)
		counters[i] = 0;

	int repeated_number = -1;
	for (int i = 0; i < size; i++)
	{
		counters[numbers_array[i]] = counters[numbers_array[i]] + 1;
		if (counters[numbers_array[i]] > 1)
		{
			repeated_number = numbers_array[i];
			break;
		}
	}

	delete[] counters;

	return repeated_number;
}

bool does_array_contains_number(int * numbers_array, int size, int number)
{
	int beginning = 0;
	int end = size-1;
	int middle_position = size/2;
	while ((end - beginning) > 1)
	{
		if (numbers_array[middle_position] == number)
		{
			return true;
		}
		else
		{
			if (numbers_array[middle_position] > number)
				end = middle_position;
			else
				beginning = middle_position;
		}

		if (end - beginning == 1)
		{
			if (numbers_array[beginning] == number || numbers_array[end] == number)
				return true;
		}
		middle_position = beginning + (end - beginning)/2;
	}
	return false;
}

bool does_matrix_contains_number(int ** numbers_array, int rows, int columns, int number)
{
	bool found = false;
	for (int i = 0; i < rows && !found; i++)
	{
		if (numbers_array[i][0] <= number && numbers_array[i][columns-1] >= number) 
		{
			found = does_array_contains_number(numbers_array[i], columns, number);
		}
	}

	return found;
}

bool find_core(int ** numbers_array, int rows, int columns, int number, int row1, int col1, int row2, int col2)
{
	if (numbers_array[row1][col1] > number || numbers_array[row2][col2] < number)
		return false;
	if (numbers_array[row1][col1] == number || numbers_array[row2][col2] == number)
		return true;

	int mid_row = (row1 + row2)/2;
	int mid_col = (col1 + col2)/2;
	int original_row1 = row1;
	int original_row2 = row2;
	int original_col1 = col1;
	int original_col2 = col2;

	while ((mid_row != row1 || mid_col != col1) && (mid_row != row2 || mid_col != col2))
	{
		if (numbers_array[mid_row][mid_col] == number)
			return true;

		if (numbers_array[mid_row][mid_col] > number)
		{
			row2 = mid_row;
			col2 = mid_col;
		}
		else
		{
			row1 = mid_row;
			col1 = mid_col;
		}

		mid_row = (row1 + row2)/2;
		mid_col = (col1 + col2)/2;
	}

	bool found = false;
	if (mid_row < rows-1)
		found = find_core(numbers_array, rows, columns, number, mid_row+1, original_col1, original_row2, mid_col);
	if (!found && mid_col < columns-1)
		found = find_core(numbers_array, rows, columns, number, original_row1, mid_col+1, mid_row, original_col2);

	return found;
}

bool does_matrix_contains_number_via_diagonal(int ** numbers_array, int rows, int columns, int number)
{
	return find_core(numbers_array, rows, columns, number, 0, 0, rows-1, columns-1);
}

void merge_data_left(int * final_array, int * left_array, int final_index, int left_index)
{
	while (left_index >= 0)
	{
		final_array[final_index] = left_array[left_index];
		final_index --;
		left_index --;
	}
}

void merge_arrays(int * first_array, int * second_array, int first_array_size, int second_array_size)
{
	int first_array_index = first_array_size - 1;
	int second_array_index = second_array_size - 1;
	int final_array_index = first_array_size + second_array_size - 1;

	while (first_array_index >= 0 && second_array_index >= 0)
	{	
		if (first_array[first_array_index] > second_array[second_array_index])
		{
			first_array[final_array_index] = first_array[first_array_index];
			first_array_index --;
		}
		else
		{
			first_array[final_array_index] = second_array[second_array_index];
			second_array_index --;
		}

		final_array_index --;
	}

	merge_data_left(first_array, second_array, final_array_index, second_array_index);
}

bool recursive_match(std::string pattern, std::string string_to_match, int pattern_position, int string_position)
{
	if (pattern_position == pattern.length() && string_position == string_to_match.length())
		return true;
	if (pattern_position == pattern.length() && string_position < string_to_match.length())
		return false;

	if (pattern_position+1 < pattern.length() && pattern[pattern_position+1] == '*')
	{
		if (pattern[pattern_position] == string_to_match[string_position] || (pattern[pattern_position] == '.' && string_position < string_to_match.length()))
		{
			return recursive_match(pattern, string_to_match, pattern_position + 2, string_position + 1) ||
				   recursive_match(pattern, string_to_match, pattern_position, string_position + 1) ||
				   recursive_match(pattern, string_to_match, pattern_position + 2, string_position);
		}
		else
			return recursive_match(pattern, string_to_match, pattern_position + 2, string_position);
	}
	if (pattern[pattern_position] == string_to_match[string_position] || (pattern[pattern_position] == '.' && string_position < string_to_match.length()))
		return recursive_match(pattern, string_to_match, pattern_position + 1, string_position + 1);
	return false;
}

bool match(std::string pattern, std::string string_to_match)
{
	return recursive_match(pattern, string_to_match, 0, 0);
}

bool is_number_char(char number_char)
{
	return (number_char >= '0' && number_char <= '9');
}

bool is_sign(char sign_char)
{
	return (sign_char == '+' || sign_char == '-');
}

bool is_decimal_dot(char decimal_char)
{
	return (decimal_char == '.');
}

bool is_exponential(char exponential_char)
{
	return (exponential_char == 'e' || exponential_char == 'E');
}

bool is_number(std::string number)
{
	if (number == "")
		return false;

	int position = 0;
	if (!is_number_char(number[0]) && is_sign(number[0]))
			position = 1;

	while (position < number.length() && is_number_char(number[position]) && !is_decimal_dot(number[position]) && !is_exponential(number[position]))
		position ++;

	if (position == number.length())
		return true;

	if (is_decimal_dot(number[position]))
	{
		position ++;
		while (position < number.length() && is_number_char(number[position]) && !is_exponential(number[position]))
			position ++;
		if (position == number.length())
			return true;
	}

	if (is_exponential(number[position]))
	{
		position ++;
		if (position == number.length())
			return false;
		if (!is_number_char(number[position]) && is_sign(number[position]))
			position ++;
		if (position == number.length())
			return false;
		while (position < number.length() && is_number_char(number[position]))
			position ++;
		if (position == number.length())
			return true;
	}

	return false;
}

bool valid_position(char **matrix, bool **visited, int rows, int columns, int x_position, int y_position, char current_char)
{
	if (x_position >= 0 && x_position < rows && y_position >= 0 && y_position < columns && 
		!visited[x_position][y_position] && matrix[x_position][y_position] == current_char)
		return true;
	return false;
}

bool move(char **matrix, bool **visited, int rows, int columns, int x_position, int y_position, std::string string_to_find, int string_position)
{
	if (string_position == string_to_find.length())
		return true;

	bool can_move = false;
	if (valid_position(matrix, visited, rows, columns, x_position, y_position, string_to_find[string_position]))
	{
		string_position ++;
		visited[x_position][y_position] = true;
		can_move = move(matrix, visited, rows, columns, x_position + 1, y_position, string_to_find, string_position) ||
						move(matrix, visited, rows, columns, x_position, y_position + 1, string_to_find, string_position) ||
						move(matrix, visited, rows, columns, x_position - 1, y_position, string_to_find, string_position) ||
						move(matrix, visited, rows, columns, x_position, y_position - 1, string_to_find, string_position);

		if (!can_move)
			visited[x_position][y_position] = false;
	}

	return can_move;
}

bool does_matrix_contains_string(char ** matrix, int rows, int columns, std::string string_to_find)
{
	bool ** visited = new (std::nothrow) bool*[rows];
	for (int i = 0; i < rows; i++)
		visited[i] = new (std::nothrow) bool[columns];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			visited[i][j] = false;

	bool found = false;
	for (int i = 0; i < rows && !found; i++)
		for (int j = 0; j < columns && !found; j++)
		{
			found = move(matrix, visited, rows, columns, i, j, string_to_find, 0);
		}

	for (int i = 0; i < rows; i++)
		delete[] visited[i];
	delete[] visited;	

	return found;
}
