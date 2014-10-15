#include <stack>
#include <string>
#include <map>

double get_max_profit(double * stock_prices_yesterday, int lenght);
int get_number_of_denominations(int amount, int * denominations, int size);
int get_closing_parentheses_position(std::string sentence, int openning_position);
int find_closing_parentheses(std::string sentence, int openning_position);
int find_repeated_number(int * numbers, int length);
bool could_be_a_palindrome(std::string word);
int get_number_of_denominations2(int amount, int * denominations, int size);
std::map<std::string, int> get_word_cloud(const std::string &text);
