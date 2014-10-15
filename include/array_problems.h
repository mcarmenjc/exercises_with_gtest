#include <string>

int repeated_number(int * numbers_array, int size);
bool does_array_contains_number(int * numbers_array, int size, int number);
bool does_matrix_contains_number(int ** numbers_array, int rows, int columns, int number);
bool find_core(int ** numbers_array, int rows, int columns, int number, int row1, int col1, int row2, int col2);
bool does_matrix_contains_number_via_diagonal(int ** numbers_array, int rows, int columns, int number);
void merge_arrays(int * first_array, int * second_array, int first_array_size, int second_array_size);
bool recursive_match(std::string pattern, std::string string_to_match, int pattern_position, int string_position);
bool match(std::string pattern, std::string string_to_match);
bool is_number(std::string number);
bool does_matrix_contains_string(char ** matrix, int rows, int columns, std::string string_to_find);
