#include "../include/array.h"
#include "gtest/gtest.h"
#include <iostream>

class ArrayTest : public ::testing::Test {
protected:
	void SetUp()
	{
		unsorted_array.set_at(0, 3);
		unsorted_array.set_at(1, 7);
		unsorted_array.set_at(2, 8);
		unsorted_array.set_at(3, 5);
		unsorted_array.set_at(4, 2);
		unsorted_array.set_at(5, 1);
		unsorted_array.set_at(6, 9);
		unsorted_array.set_at(7, 5);
		unsorted_array.set_at(8, 4);	
	}
	Array unsorted_array= Array(9);
};

TEST_F(ArrayTest, ElementsAreCorrectlySetedAndGetedFromArray)
{
	Array array = Array(5);
	for (int i = 0; i < array.get_length(); i++)
		array.set_at(i, i);
	for (int i = 0; i < array.get_length(); i++)
		ASSERT_EQ(i, array.get_at(i));
}

TEST_F(ArrayTest, ArrayIsCorrectlySortedUsingInsertSort)
{
	unsorted_array.insert_sort();
	for (int i = 1; i < unsorted_array.get_length(); i++)
	{
		ASSERT_TRUE(unsorted_array.get_at(i-1) <= unsorted_array.get_at(i));
	}
}

TEST_F(ArrayTest, ArrayIsCorrectlySortedUsingBubbleSort)
{
	unsorted_array.bubble_sort();
	for (int i = 1; i < unsorted_array.get_length(); i++)
	{
		ASSERT_TRUE(unsorted_array.get_at(i-1) <= unsorted_array.get_at(i));
	}
}

TEST_F(ArrayTest, ArrayIsCorrectlySortedUsingMergeSort)
{
	unsorted_array.merge_sort();
	for (int i = 1; i < unsorted_array.get_length(); i++)
	{
		ASSERT_TRUE(unsorted_array.get_at(i-1) <= unsorted_array.get_at(i));
	}
}

TEST_F(ArrayTest, ArrayIsCorrectlySortedUsingQuickSort)
{
	unsorted_array.quick_sort();
	for (int i = 1; i < unsorted_array.get_length(); i++)
	{
		ASSERT_TRUE(unsorted_array.get_at(i-1) <= unsorted_array.get_at(i));
	}
}

TEST_F(ArrayTest, ArrayIsCorrectlySortedUsingCountSort)
{
	unsorted_array.count_sort();
	for (int i = 1; i < unsorted_array.get_length(); i++)
	{
		ASSERT_TRUE(unsorted_array.get_at(i-1) <= unsorted_array.get_at(i));
	}
}

TEST_F(ArrayTest, ElementFoundUsingBinarySearch)
{
	Array array = Array(5);
	for (int i = 0; i < array.get_length(); i++)
		array.set_at(i, i);
	ASSERT_EQ(1, array.binary_search(1));
}

TEST_F(ArrayTest, ElementFoundUsingIterativeBinarySearch)
{
	Array array = Array(5);
	for (int i = 0; i < array.get_length(); i++)
		array.set_at(i, i);
	ASSERT_EQ(1, array.binary_search_iterative(1));
}

TEST_F(ArrayTest, MinimumElementFoundInPartiallyOrderedArray)
{
	Array array = Array(5);
	for (int i = 3, j = 0; i <= array.get_length(); i++, j++)
		array.set_at(j, i);
	for (int i = 1, j = 3; i < 3; i++, j++)
		array.set_at(j, i);
	ASSERT_EQ(1, array.min_value_in_partial_ordered_array());
}

TEST_F(ArrayTest, MinimumElementFoundInPartiallyOrderedArrayWithAllElementsEqualAndMinimumAtLeft)
{
	Array array = Array(5);
	array.set_at(0, 1);
	array.set_at(1, 0);
	array.set_at(2, 1);
	array.set_at(3, 1);
	array.set_at(4, 1);
	ASSERT_EQ(0, array.min_value_in_partial_ordered_array());
}

TEST_F(ArrayTest, MinimumElementFoundInPartiallyOrderedArrayWithAllElementsEqualAndMinimumAtRight)
{
	Array array = Array(5);
	array.set_at(0, 1);
	array.set_at(1, 1);
	array.set_at(2, 1);
	array.set_at(3, 0);
	array.set_at(4, 1);
	ASSERT_EQ(0, array.min_value_in_partial_ordered_array());
}

TEST_F(ArrayTest, PositionOfTurningElementIsCorrectlyGetted)
{
	Array array = Array(10);
	for (int i = 1; i <= 5; i++)
		array.set_at(i-1, i);
	for (int i = 10, j = 5; i >=6; i--, j++)
		array.set_at(j, i);
	ASSERT_EQ(5, array.get_turning_position());
}

TEST_F(ArrayTest, NoTurningElementFoundInArrayWithEqualElements)
{
	Array array = Array(10);
	for (int i = 0; i < 10; i++)
		array.set_at(i, 1);
	ASSERT_EQ(-1, array.get_turning_position());
}

TEST_F(ArrayTest, NoTurningElementFoundInOrderedArray)
{
	Array array = Array(10);
	for (int i = 0; i < 10; i++)
		array.set_at(i, i);
	ASSERT_EQ(-1, array.get_turning_position());
}

TEST_F(ArrayTest, TurningElementFoundInAThreeElementsArray)
{
	Array array = Array(3);
	array.set_at(0, 1);
	array.set_at(1, 3);
	array.set_at(2, 2);
	ASSERT_EQ(1, array.get_turning_position());
}

TEST_F(ArrayTest, NoTurningElementFoundInAThreeElementsArray)
{
	Array array = Array(3);
	array.set_at(0, 1);
	array.set_at(1, 5);
	array.set_at(2, 6);
	ASSERT_EQ(-1, array.get_turning_position());
}

TEST_F(ArrayTest, MajorityElementCorrectlyFoundUsingPartitionMethod)
{
	Array array = Array(9);
	array.set_at(0, 1);
	array.set_at(1, 2);
	array.set_at(2, 3);
	array.set_at(3, 2);
	array.set_at(4, 2);
	array.set_at(5, 2);
	array.set_at(6, 5);
	array.set_at(7, 4);
	array.set_at(8, 2);
	ASSERT_EQ(2, array.find_majority_element_using_partition());
}

TEST_F(ArrayTest, NoMajorityElementCorrectlyFoundUsingPartitionMethod)
{
	Array array = Array(10);
	for (int i = 0; i < 10; i++)
		array.set_at(i, i);
	ASSERT_EQ(-1, array.find_majority_element_using_partition());
}

TEST_F(ArrayTest, MajorityElementCorrectlyFound)
{
	Array array = Array(9);
	array.set_at(0, 1);
	array.set_at(1, 2);
	array.set_at(2, 3);
	array.set_at(3, 2);
	array.set_at(4, 2);
	array.set_at(5, 2);
	array.set_at(6, 5);
	array.set_at(7, 4);
	array.set_at(8, 2);
	ASSERT_EQ(2, array.find_majority_element());
}

TEST_F(ArrayTest, NoMajorityElementCorrectlyFound)
{
	Array array = Array(10);
	for (int i = 0; i < 10; i++)
		array.set_at(i, i);
	ASSERT_EQ(-1, array.find_majority_element());
}