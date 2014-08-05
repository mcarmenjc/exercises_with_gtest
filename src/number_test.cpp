#include "../include/number.h"
#include "gtest/gtest.h"

class TestNumber : public ::testing::Test {
protected:
	Number test_case1 = Number(121);
	Number test_case2 = Number(122);
};

TEST_F(TestNumber, IsPalindromeShouldReturnTrueForNumber121)
{
	EXPECT_EQ(true, test_case1.is_palindrome());
}

TEST_F(TestNumber, IsPalindromeShouldReturnFalseForNumber122)
{
	EXPECT_EQ(false, test_case2.is_palindrome());
}