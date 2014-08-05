#include "../include/array_problems.h"
#include <iostream>

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