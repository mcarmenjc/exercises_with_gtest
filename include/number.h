#ifndef NUMBER
#define NUMBER

class Number {
public:
	Number(long number);
	bool is_palindrome();
	long reverse_number();
	long fibonacci_recursive();
	long fibonacci_iterative();
	long fibonacci_using_matrix();
private:
	long no;
	long fibonacci_recursive_core(long actual_n);
};

#endif
