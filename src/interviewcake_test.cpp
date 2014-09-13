#include "../include/interviewcake.h"
#include "gtest/gtest.h"
#include <string>
#include <new>

TEST(InterviewCakeTest, MaxProfitShouldBeCorrectlyCalculated)
{
	double * stock_prices_yesterday = new (std::nothrow) double[10];
	stock_prices_yesterday[0] = 10;
	stock_prices_yesterday[1] = 200;
	stock_prices_yesterday[2] = 500;
	stock_prices_yesterday[3] = 5;
	stock_prices_yesterday[4] = 1000;
	stock_prices_yesterday[5] = 50;
	stock_prices_yesterday[6] = 1500;
	stock_prices_yesterday[7] = 20;
	stock_prices_yesterday[8] = 11;
	stock_prices_yesterday[9] = 300;
	double max_profit = get_max_profit(stock_prices_yesterday, 10);
	delete[] stock_prices_yesterday;
	ASSERT_EQ(1495, max_profit);
}

TEST(InterviewCakeTest, GetNumberOfDenominationsForASetAmountShouldBeCorrect)
{
	int * denominations = new (std::nothrow) int[3];
	denominations[0] = 1;
	denominations[1] = 2;
	denominations[2] = 3;
	int number_of_denominations = get_number_of_denominations(4, denominations, 3);
	delete[] denominations;
	ASSERT_EQ(4, number_of_denominations);
}

TEST(InterviewCakeTest, CorrectPositionOfEndingParenthesesShouldBeFound)
{
	std::string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
	int ending_position = find_closing_parentheses(sentence, 10);
	ASSERT_EQ(79, ending_position);
}

TEST(InterviewCakeTest, InvalidPositionShouldBeReturnedWhenCharacterAtOpenningPositionIsNotAParentheses)
{
	std::string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
	int ending_position = find_closing_parentheses(sentence, 9);
	ASSERT_EQ(-1, ending_position);
}

TEST(InterviewCakeTest, InvalidPositionShouldBeReturnedWhenOpenningPositionIsOutOfRange)
{
	std::string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
	int ending_position = find_closing_parentheses(sentence, -1);
	ASSERT_EQ(-1, ending_position);
}

TEST(InterviewCakeTest, InvalidPositionShouldBeReturnedWhenNoEndingParentheses)
{
	std::string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this)) they get confusing.";
	int ending_position = find_closing_parentheses(sentence, 10);
	ASSERT_EQ(-1, ending_position);
}

TEST(InterviewCakeTest, CorrectPositionOfEndingParenthesesShouldBeFoundUsingAStack)
{
	std::string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
	int ending_position = get_closing_parentheses_position(sentence, 10);
	ASSERT_EQ(79, ending_position);
}

TEST(InterviewCakeTest, InvalidPositionShouldBeReturnedWhenCharacterAtOpenningPositionIsNotAParenthesesUsingAStack)
{
	std::string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
	int ending_position = get_closing_parentheses_position(sentence, 9);
	ASSERT_EQ(-1, ending_position);
}

TEST(InterviewCakeTest, InvalidPositionShouldBeReturnedWhenOpenningPositionIsOutOfRangeUsingAStack)
{
	std::string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";
	int ending_position = get_closing_parentheses_position(sentence, -1);
	ASSERT_EQ(-1, ending_position);
}

TEST(InterviewCakeTest, InvalidPositionShouldBeReturnedWhenNoEndingParenthesesUsingAStack)
{
	std::string sentence = "Sometimes (when I nest them (my parentheticals) too much (like this (and this)) they get confusing.";
	int ending_position = get_closing_parentheses_position(sentence, 10);
	ASSERT_EQ(-1, ending_position);
}

TEST(InterviewCakeTest, CorrectlyFindTheRepeatedNumberInARange)
{
	int * numbers = new (std::nothrow) int[10];
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	numbers[4] = 5;
	numbers[5] = 6;
	numbers[6] = 7;
	numbers[7] = 8;
	numbers[8] = 9;
	numbers[9] = 9;
	int repeated_number = find_repeated_number(numbers, 10);
	delete[] numbers;
	ASSERT_EQ(9, repeated_number);
}