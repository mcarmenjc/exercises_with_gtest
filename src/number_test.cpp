#include "../include/number.h"
#include "gtest/gtest.h"

TEST(NumberTest, IsPalindromeShouldReturnTrueForNumber121)
{
	Number test_case1 = Number(121);
	ASSERT_TRUE(test_case1.is_palindrome());
}

TEST(NumberTest, IsPalindromeShouldReturnFalseForNumber122)
{
	Number test_case2 = Number(122);
	ASSERT_FALSE(test_case2.is_palindrome());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedRecursively)
{
	Number fibonacci_test = Number(5);
	ASSERT_EQ(5, fibonacci_test.fibonacci_recursive());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedRecursivelyFor0)
{
	Number fibonacci_test = Number(0);
	ASSERT_EQ(0, fibonacci_test.fibonacci_recursive());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedRecursivelyFor1)
{
	Number fibonacci_test = Number(1);
	ASSERT_EQ(1, fibonacci_test.fibonacci_recursive());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedIteratively)
{
	Number fibonacci_test = Number(5);
	ASSERT_EQ(5, fibonacci_test.fibonacci_iterative());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedIterativelyFor0)
{
	Number fibonacci_test = Number(0);
	ASSERT_EQ(0, fibonacci_test.fibonacci_iterative());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedIterativelyFor1)
{
	Number fibonacci_test = Number(1);
	ASSERT_EQ(1, fibonacci_test.fibonacci_iterative());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedUsingMatrix)
{
	Number fibonacci_test = Number(5);
	ASSERT_EQ(5, fibonacci_test.fibonacci_using_matrix());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedUsingMatrixFor0)
{
	Number fibonacci_test = Number(0);
	ASSERT_EQ(0, fibonacci_test.fibonacci_using_matrix());
}

TEST(NumberTest, FibonacciValueCorrectlyCalculatedUsingMatrixFor1)
{
	Number fibonacci_test = Number(1);
	ASSERT_EQ(1, fibonacci_test.fibonacci_using_matrix());
}