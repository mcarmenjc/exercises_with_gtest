#include "../include/array.h"
#include <new>
#include <iostream>

Array::Array()
{
	length = 0;
	data = 0;
}

Array::Array(int num_elements)
{
	if (num_elements > 0)
	{
		length = num_elements;
		data = new (std::nothrow) int[length];
	}
}

Array::Array(const Array &array)
{
	if (array.length > 0 && array.data != 0)
	{
		length = array.length;
		data = new (std::nothrow) int[length];

		for (int i = 0; i < length; i++)
			data[i] = array.data[i];
	}
}

Array::~Array()
{
	if (length > 0 && data != 0)
		delete [] data;
}

void Array::set_at(int pos, int value)
{
	if (pos >= 0 && pos < length)
		data[pos] = value;
}

int Array::get_at(int pos)
{
	if (pos >= 0 && pos < length)
		return data[pos];
	return 0;
}

int Array::get_length()
{
	return length;
}

void Array::insert_sort()
{
	for (int i = 1; i < length; i++)
	{
		int value = data[i];
		int j = i-1;
		while (j >= 0 && data[j] > value)
		{
			data[j+1] = data[j];
			j--;
		}
		data[j+1] = value;
	}
}

void Array::bubble_sort()
{
	bool swapped = true;
	int num_elements = length;

	while (swapped)
	{
		swapped = false;
		for (int i = 1; i < num_elements; i++)
		{
			if (data[i-1] > data[i])
			{
				swap(i-1, i);
				swapped = true;
			}
		}	
		num_elements --;
	}
	
}

void Array::swap(int first_position, int second_position)
{
	int aux_value = data[first_position];
	data[first_position] = data[second_position];
	data[second_position] = aux_value;
}

void Array::merge_sort()
{
	merge_sort_core(0, length-1);
}

void Array::merge_sort_core(int beginning, int end)
{
	int size = end - beginning + 1;
	if (size > 1)
	{
		int middle_position = beginning + size/2;
		merge_sort_core(beginning, middle_position-1);
		merge_sort_core(middle_position, end);
		merge_subarrays(beginning, middle_position, end);
	}
}

void Array::merge_subarrays(int beginning, int middle, int end)
{
	int first_iterator = beginning;
	int second_iterator = middle;
	int size = end - beginning + 1;
	Array merged_subarray = Array(size);
	int merged_iterator = 0;
	while (first_iterator < middle && second_iterator <= end)
	{
		if (data[first_iterator] < data[second_iterator])
		{
			merged_subarray.data[merged_iterator] = data[first_iterator];
			first_iterator ++;
		}
		else
		{
			merged_subarray.data[merged_iterator] = data[second_iterator];
			second_iterator ++;	
		}

		merged_iterator ++;
	}

	copy_subarray(merged_subarray, merged_iterator, first_iterator, middle);
	copy_subarray(merged_subarray, merged_iterator, second_iterator, end+1);
	copy_sorted_data_back(merged_subarray, beginning);
}

void Array::copy_subarray(Array &array, int array_position, int subarray_beginning, int subarray_end)
{
	while (subarray_beginning < subarray_end)
	{
		array.data[array_position] = data[subarray_beginning];
		subarray_beginning ++;
		array_position ++;
	}
}

void Array::copy_sorted_data_back(const Array &array, int beginning)
{
	for (int i = 0, j = beginning; i < array.length; i++, j++)
		data[j] = array.data[i];
}

void Array::quick_sort()
{
	quick_sort_core(0, length-1);
}

int Array::partition(int beginning, int end)
{
	int pivot_iterator = end;
	int beginning_iterator = beginning;

	while (beginning_iterator <= pivot_iterator-1)
	{
		if (data[beginning_iterator] > data[pivot_iterator])
		{
			swap(beginning_iterator, pivot_iterator-1);
			swap(pivot_iterator-1, pivot_iterator);
			pivot_iterator--;
		}
		else
		{
			beginning_iterator++;
		}
	}

	return pivot_iterator;
}

void Array::quick_sort_core(int beginning, int end)
{
	if (end - beginning + 1 > 1)
	{
		int pivot_position = partition(beginning, end);
		quick_sort_core(beginning, pivot_position-1);
		quick_sort_core(pivot_position+1, end);
	}
}

void Array::count_sort()
{
	int max_value = get_max_value();
	Array count_array = Array(max_value + 1);

	for (int i = 0, j = 0; i < count_array.length; i++)
		count_array.data[i] = 0;

	for (int i = 0; i < length; i++)
	{
		count_array.data[data[i]] ++;
	}

	for (int i = 0, j = 0; i < count_array.length; i++)
	{
		for (int k = 0; k < count_array.data[i]; k++, j++)
			data[j] = i;
	}
}

int Array::get_max_value()
{
	int max_value = data[0];

	for (int i = 1; i < length; i++)
		if (data[i] > max_value)
			max_value = data[i];
}

int Array::binary_search(int value)
{
	return binary_search_core(value, 0, length-1);
}

int Array::binary_search_core(int value, int beginning, int end)
{
	if (beginning == end)
	{
		if (value != data[beginning])
			return -1;
		else
			return beginning;
	}

	int mid_position = beginning + (end - beginning + 1)/2;
	if (value == data[mid_position])
		return mid_position;
	else
	{
		if (data[mid_position] > value)
			return binary_search_core(value, beginning, mid_position-1);
		else
			return binary_search_core(value, mid_position+1, end);
	}
}

int Array::binary_search_iterative(int value)
{
	int beginning = 0;
	int end = length-1;
	int middle_position = length/2;
	while ((end - beginning) > 1)
	{
		if (data[middle_position] == value)
		{
			return middle_position;
		}
		else
		{
			if (data[middle_position] > value)
				end = middle_position;
			else
				beginning = middle_position;
		}

		if (end - beginning == 1)
		{
			if (data[beginning] == value)
				return beginning;
			if (data[end] == value)
				return end;
		}
		middle_position = beginning + (end - beginning)/2;
	}
	return false;
}

int Array::min_value_in_partial_ordered_array()
{
	int beginning_iterator = 0;
	int end_iterator = length - 1;
	int mid_position;
	while (beginning_iterator < end_iterator)
	{
		mid_position = beginning_iterator + (end_iterator - beginning_iterator + 1)/2;
		if (end_iterator - beginning_iterator == 1)
		{
			beginning_iterator = end_iterator;
		}
		if (data[beginning_iterator] == data[mid_position] && data[mid_position] == data[end_iterator])
		{
			return min_value_sequentially(beginning_iterator, end_iterator);
		}
		if (data[mid_position] > data[beginning_iterator])
			beginning_iterator = mid_position;
		else
			end_iterator = mid_position;
	}

	return data[mid_position];
}

int Array::min_value_sequentially(int beginning, int end)
{
	int min_value = data[beginning];
	for (int i = beginning + 1; i < end; i++)
	{
		if (min_value > data[i])
			min_value = data[i];
	}

	return min_value;
}

int Array::get_turning_position()
{
	int beginning_iterator = 0;
	int end_iterator = length - 1;
	int mid_position;
	while (beginning_iterator + 1 < end_iterator)
	{
		mid_position = beginning_iterator + (end_iterator - beginning_iterator + 1)/2;
		if (mid_position == 0 || mid_position == length-1)
			return -1;
		if (data[mid_position] > data[mid_position-1] && data[mid_position] > data[mid_position + 1])
			return mid_position;

		if (data[mid_position] > data[mid_position-1] && data[mid_position] < data[mid_position + 1])
			beginning_iterator = mid_position;
		else
			end_iterator = mid_position;
	}

	return -1;
}

int Array::find_majority_element_using_partition()
{
	int beginning = 0;
	int end = length-1;
	int mid_position = length/2;
	int pivot_position = partition(beginning, end);
	while (pivot_position != mid_position)
	{
		if (pivot_position > mid_position)
		{
			end = pivot_position - 1;
		}
		else
		{
			beginning = pivot_position + 1;
		}
		pivot_position = partition(beginning, end);
	}

	if (check_majority(data[mid_position]))
		return data[mid_position];
	else
		return -1;
}

bool Array::check_majority(int value)
{
	int num_appearance = 0;

	for (int i = 0; i < length; i++)
	{
		if (data[i] == value)
			num_appearance ++;
	}

	return num_appearance > length/2;
}

int Array::find_majority_element()
{
	int visited = 1;
	int majority_element = data[0];

	for (int i = 1; i < length; i++)
	{
		if (visited == 0)
		{
			visited = 1;
			majority_element = data[i];
		}
		else
		{
			if (data[i] == majority_element)
				visited ++;
			else
				visited --;
		}
	}

	if (check_majority(majority_element))
		return majority_element;
	else
		return -1;
}