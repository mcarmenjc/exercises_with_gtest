#include "../include/array_problems.h"
#include "gtest/gtest.h"
#include <string>
#include <new>

TEST(TestArrayProblems, RepeatedNumberShouldBeFound)
{
	int * numbers_array_1 = new int[6];
	numbers_array_1[0] = 0;
	numbers_array_1[1] = 1;
	numbers_array_1[2] = 1;
	numbers_array_1[3] = 2;
	numbers_array_1[4] = 3;
	numbers_array_1[5] = 4;
	int number = repeated_number(numbers_array_1, 6);
	delete [] numbers_array_1;
	EXPECT_EQ(1, number);
}

TEST(TestArrayProblems, ArrayWithNoRepeatedNumber)
{
	int * numbers_array_2 = new int[6];
	numbers_array_2[0] = 0;
	numbers_array_2[1] = 1;
	numbers_array_2[2] = 5;
	numbers_array_2[3] = 2;
	numbers_array_2[4] = 3;
	numbers_array_2[5] = 4;
	int number = repeated_number(numbers_array_2, 6);
	delete [] numbers_array_2;
	EXPECT_EQ(-1, number);
}

TEST(TestArrayProblems, MatrixContainsNumber)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number(matrix, 3, 3, 3);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(true, found);
}

TEST(TestArrayProblems, MatrixContainsFirstNumber)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number(matrix, 3, 3, 1);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(true, found);
}

TEST(TestArrayProblems, MatrixContainsLastNumber)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number(matrix, 3, 3, 17);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(true, found);
}

TEST(TestArrayProblems, MatrixDoesNotContainNumber)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number(matrix, 3, 3, 2);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(false, found);
}

TEST(TestArrayProblems, MatrixDoesNotContainNumberOutsideLimits)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number(matrix, 3, 3, 20);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(false, found);
}

TEST(TestArrayProblems, MatrixContainsNumberUsingDiagonal)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number_via_diagonal(matrix, 3, 3, 3);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(true, found);
}

TEST(TestArrayProblems, MatrixContainsFirstNumberUsingDiagonal)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number_via_diagonal(matrix, 3, 3, 1);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(true, found);
}

TEST(TestArrayProblems, MatrixContainsLastNumberUsingDiagonal)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number_via_diagonal(matrix, 3, 3, 17);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(true, found);
}

TEST(TestArrayProblems, MatrixDoesNotContainNumberUsingDiagonal)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number_via_diagonal(matrix, 3, 3, 2);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(false, found);
}

TEST(TestArrayProblems, MatrixDoesNotContainNumberOutsideLimitsUsingDiagonal)
{
	int ** matrix = new int * [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int [3];
	}
	
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[1][0] = 7;
	matrix[1][1] = 9;
	matrix[1][2] = 11;
	matrix[2][0] = 13;
	matrix[2][1] = 15;
	matrix[2][2] = 17;

	bool found = does_matrix_contains_number_via_diagonal(matrix, 3, 3, 20);

	for (int i = 0; i < 3; i++)
		delete [] matrix[i];
	delete [] matrix;
	EXPECT_EQ(false, found);
}

TEST(TestArrayProblems, ArraysAreCorrectlyMerged)
{
	int * first_array = new int[12];
	first_array[0] = 0;
	first_array[1] = 1;
	first_array[2] = 5;
	first_array[3] = 6;
	first_array[4] = 9;
	first_array[5] = 10;
	int * second_array = new int[6];
	second_array[0] = 2;
	second_array[1] = 3;
	second_array[2] = 4;
	second_array[3] = 7;
	second_array[4] = 8;
	second_array[5] = 11;
	merge_arrays(first_array, second_array, 6, 6);

	for (int i = 0; i < 12; i++)
	{
		EXPECT_EQ(i, first_array[i]);
	}

	delete [] first_array;
	delete [] second_array;
}

TEST(TestArrayProblems, ArraysAreCorrectlyMergedWithRepeatedValues)
{
	int * first_array = new int[12];
	first_array[0] = 0;
	first_array[1] = 1;
	first_array[2] = 5;
	first_array[3] = 6;
	first_array[4] = 9;
	first_array[5] = 10;
	int * second_array = new int[6];
	second_array[0] = 1;
	second_array[1] = 3;
	second_array[2] = 4;
	second_array[3] = 6;
	second_array[4] = 8;
	second_array[5] = 11;
	merge_arrays(first_array, second_array, 6, 6);

	EXPECT_EQ(0, first_array[0]);
	EXPECT_EQ(1, first_array[1]);
	EXPECT_EQ(1, first_array[2]);
	EXPECT_EQ(3, first_array[3]);
	EXPECT_EQ(4, first_array[4]);
	EXPECT_EQ(5, first_array[5]);
	EXPECT_EQ(6, first_array[6]);
	EXPECT_EQ(6, first_array[7]);
	EXPECT_EQ(8, first_array[8]);
	EXPECT_EQ(9, first_array[9]);
	EXPECT_EQ(10, first_array[10]);
	EXPECT_EQ(11, first_array[11]);

	delete [] first_array;
	delete [] second_array;
}

TEST(TestArrayProblems, StringAAAMatchesPattern1)
{
	std::string pattern = "a.a";
	std::string string_to_check = "aaa";
	bool is_match = match(pattern, string_to_check);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringAAAMatchesPattern2)
{
	std::string pattern = "ab*ac*a";
	std::string string_to_check = "aaa";
	bool is_match = match(pattern, string_to_check);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringAAADoesNotMatchPattern3)
{
	std::string pattern = "aa.a";
	std::string string_to_check = "aaa";
	bool is_match = match(pattern, string_to_check);
	EXPECT_EQ(false, is_match);
}

TEST(TestArrayProblems, StringAAADoesNotMatchPattern4)
{
	std::string pattern = "ab*a";
	std::string string_to_check = "aaa";
	bool is_match = match(pattern, string_to_check);
	EXPECT_EQ(false, is_match);
}

TEST(TestArrayProblems, StringIntegerIsCorrectNumber)
{
	std::string number = "123";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringIntegerWithPositiveSignIsCorrectNumber)
{
	std::string number = "+123";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringIntegerWithNegativeSignIsCorrectNumber)
{
	std::string number = "-123";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringFloatIsCorrectNumber)
{
	std::string number = "123.";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringFloatWithNegativeSignIsCorrectNumber)
{
	std::string number = "-123.";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringFloatWithDecimalsIsCorrectNumber)
{
	std::string number = "123.123";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringFloatWithDecimalsAndsignIsCorrectNumber)
{
	std::string number = "+3.141516";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringNumberWithExponentIsCorrectNumber)
{
	std::string number = "1e1";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringNumberWithExponentAndSignIsCorrectNumber)
{
	std::string number = "1e+1";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, StringPositiveNumberWithExponentAndSignIsCorrectNumber)
{
	std::string number = "+1e+1";
	bool is_match = is_number(number);
	EXPECT_EQ(true, is_match);
}

TEST(TestArrayProblems, IncorrectDecimalNumber)
{
	std::string number = "1.2.3";
	bool is_match = is_number(number);
	EXPECT_EQ(false, is_match);
}

TEST(TestArrayProblems, IncorrectExponentialNumber)
{
	std::string number = "1e+1.3";
	bool is_match = is_number(number);
	EXPECT_EQ(false, is_match);
}

TEST(TestArrayProblems, StringCorrectlyFoundInMatrix)
{
	std::string string_to_check = "bcced";
	int rows = 3;
	int columns = 4;
	char ** matrix = new (std::nothrow) char*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new (std::nothrow) char[columns];
	matrix[0][0] = 'a';
	matrix[0][1] = 'b';
	matrix[0][2] = 'c';
	matrix[0][3] = 'e';
	matrix[1][0] = 's';
	matrix[1][1] = 'f';
	matrix[1][2] = 'c';
	matrix[1][3] = 's';
	matrix[2][0] = 'a';
	matrix[2][1] = 'd';
	matrix[2][2] = 'e';
	matrix[2][3] = 'e';

	bool found = does_matrix_contains_string(matrix, rows, columns, string_to_check);
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
	ASSERT_TRUE(found);
}

TEST(TestArrayProblems, StringNotFoundInMatrix)
{
	std::string string_to_check = "abcb";
	int rows = 3;
	int columns = 4;
	char ** matrix = new (std::nothrow) char*[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new (std::nothrow) char[columns];
	matrix[0][0] = 'a';
	matrix[0][1] = 'b';
	matrix[0][2] = 'c';
	matrix[0][3] = 'e';
	matrix[1][0] = 's';
	matrix[1][1] = 'f';
	matrix[1][2] = 'c';
	matrix[1][3] = 's';
	matrix[2][0] = 'a';
	matrix[2][1] = 'd';
	matrix[2][2] = 'e';
	matrix[2][3] = 'e';

	bool found = does_matrix_contains_string(matrix, rows, columns, string_to_check);
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
	ASSERT_FALSE(found);
}