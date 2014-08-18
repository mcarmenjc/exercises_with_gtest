#include "../include/stack_queue.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(StackQueueTest, StackIsCorrectlyEmptied)
{
	StackQueue stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	for (int i = 4; i >=1; i--)
	{
		ASSERT_EQ(i, stack.pop());
	}
}

TEST(StackQueueTest, ElementsAreCorrectlyPushedAndPoped)
{
	StackQueue stack;
	stack.push(3);
	stack.push(4);
	stack.push(1);
	stack.push(2);
	for (int i = 2; i >=1; i--)
		ASSERT_EQ(i, stack.pop());
	stack.push(5);
	stack.push(6);
	stack.push(7);
	for (int i = 7; i >=3; i--)
		ASSERT_EQ(i, stack.pop());
}