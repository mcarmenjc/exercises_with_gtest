#include "../include/interviewcake.h"
#include <iostream>

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
	for (int i = 0, j = length-1; i < j; i++, j--)
	{
		int aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
}

int get_number_of_denominations_core(int amount, int * denominations, int size, int actual_position)
{
	int num_denominations = 0;
	for (int i = actual_position; i < size && denominations[i] <= amount; i++)
	{
		if (amount  - denominations[i] == 0)
		{
			return ++num_denominations;
		}
		if (amount - denominations[i] < 0)
		{
			return num_denominations;
		}
		num_denominations += get_number_of_denominations_core(amount - denominations[i], denominations, size, i);
	}
	return num_denominations;
}

int get_number_of_denominations(int amount, int * denominations, int size)
{
	int num_denominations = 0;
	for (int i = 0; i < size && denominations[i] <= amount; i++)
	{
		num_denominations += get_number_of_denominations_core(amount - denominations[i], denominations, size, i);
	}
	return num_denominations;
}

int get_closing_parentheses_position(std::string sentence, int openning_position)
{
	if (openning_position < 0 || openning_position >= sentence.length() || sentence[openning_position] != '(')
		return -1;
	std::stack<char> parentheses_stack;
	parentheses_stack.push(sentence[openning_position]);
	int actual_position = openning_position+1;

	while (!parentheses_stack.empty() && actual_position < sentence.length())
	{
		if (sentence[actual_position] == '(')
			parentheses_stack.push(sentence[actual_position]);
		else
		{
			if (sentence[actual_position] == ')')
				parentheses_stack.pop();
		}

		actual_position++;
	}

	if (parentheses_stack.empty())
		return actual_position-1;
	return -1;
}

int find_closing_parentheses(std::string sentence, int openning_position)
{
	if (openning_position < 0 || openning_position >= sentence.length() || sentence[openning_position] != '(')
		return -1;
	int count = 1;
	int actual_position = openning_position+1;

	while (count > 0 && actual_position < sentence.length())
	{
		switch(sentence[actual_position])
		{
			case '(':
				count ++;
				break;
			case ')':
				count --;
				break;
		}
		
		actual_position++;
	}

	if (count == 0)
		return actual_position-1;
	return -1;
}

int find_repeated_number(int * numbers, int length)
{
	int max_value = 0;
	for (int i = 1; i <= length; i++)
		max_value += i;
	int total_sum = 0;
	for (int i = 0; i < length; i++)
		total_sum += numbers[i];
	return (length - (max_value - total_sum));
}

int get_number_of_denominations2(int amount, int * denominations, int size)
{
	int * combinations = new (std::nothrow) int[amount + 1];
	combinations[0] = 1;
	for (int i = 1; i < amount + 1; i++){
		combinations[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		int coin = denominations[i];
		int higher_amount_remainder;
		for (int higher_amount = coin; higher_amount <= amount; higher_amount ++){
			higher_amount_remainder = higher_amount - coin;
			combinations[higher_amount] += combinations[higher_amount_remainder];
		}
	}
	int num_combiantions = combinations[amount];
	delete [] combinations;
	return num_combiantions;
}

std::string to_lower_case(const std::string &word){
	std::string word_copy = word;
	for (int i = 0; i < word_copy.length(); i++){
		if (word_copy[i] >= 'A' && word_copy[i] <= 'Z'){
			word_copy[i] = word_copy[i] - ('Z' - 'z');
		}
	}
	return word_copy;
}

std::string remove_punctuation_symbols(const std::string &word){
	std::string word_copy = word;
	for (int i = 0; i < word_copy.length(); i++){
		if (!(word_copy[i] >= 'a' && word_copy[i] <= 'z') && !(word_copy[i] >= 'A' && word_copy[i] <= 'Z') && word_copy[i] != ' ' && word_copy[i] != '-' && word_copy[i] != '\''){
			word_copy[i] = ' ';
		}
	}
	return word_copy;
}

std::string remove_repeated_spaces(const std::string &word){
	std::string word_copy = word;
	int actual_position = 0;
	for (int i = 0; i < word_copy.length(); i++, actual_position++){
		word_copy[actual_position] = word_copy[i];
		if (word_copy[i] == ' '){
			while (word_copy[i+1] == ' '){
				i++;
			}
		}
	}
	word_copy = word_copy.substr(0, actual_position);
	return word_copy;
}

void add_word_to_hash_map(std::map<std::string, int> & word_cloud, const std::string phrase, int initial_position, int length){
	std::string word = phrase.substr(initial_position, length);
	if (word_cloud.count(word) > 0){
		word_cloud[word] ++;
	}
	else{
		word_cloud[word] = 1;
	}
}

std::map<std::string, int> get_word_cloud(const std::string &text){
	std::string phrase = text;
	phrase = remove_punctuation_symbols(phrase);
	phrase = remove_repeated_spaces(phrase);
	phrase = to_lower_case(phrase);
	int initial_position = 0;
	int end_position = phrase.find(" ");
	std::map<std::string, int> word_cloud;
	int length = 0;

	while (end_position != -1){
		length = end_position - initial_position;
		add_word_to_hash_map(word_cloud, phrase, initial_position, length);
		initial_position = end_position + 1;
		end_position = phrase.find(' ', initial_position);
	}

	length = phrase.length() - initial_position;
	add_word_to_hash_map(word_cloud, phrase, initial_position, length);

	return word_cloud;
}