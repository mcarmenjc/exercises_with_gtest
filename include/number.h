#ifndef NUMBER
#define NUMBER

class Number {
public:
	Number(long number);
	bool is_palindrome();
	long reverse_number();
private:
	long no;
};

#endif
