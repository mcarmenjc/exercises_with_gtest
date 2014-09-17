#ifndef ARRAY
#define ARRAY

class Array {
public:
	Array();
	Array(int num_elements);
	Array(const Array &array);
	~Array();
	void set_at(int pos, int value);
	int get_at(int pos);
	int get_length();
	void insert_sort();
	void bubble_sort();
	void merge_sort();
	void quick_sort();
	void count_sort();
	int binary_search(int value);
	int binary_search_iterative(int value);
	int min_value_in_partial_ordered_array();
	int get_turning_position();
	int find_majority_element_using_partition();
	int find_majority_element();
	int repeated_number();
	bool is_complete_cycle_array1();
	bool is_complete_cycle_array2();
private:
	int * data;
	int length;
	void swap(int first_position, int second_position);
	void merge_subarrays(int beginning, int middle, int end);
	void merge_sort_core(int beginning, int end);
	void copy_subarray(Array &array, int array_position, int subarray_beginning, int subarray_end);
	void copy_sorted_data_back(const Array &array, int beginning);
	int partition(int beginning, int end);
	void quick_sort_core(int beginning, int end);
	int get_max_value();
	int binary_search_core(int value, int beginning, int end);
	int min_value_sequentially(int beginning, int end);
	bool check_majority(int value);
};

#endif
