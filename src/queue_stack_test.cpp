#include "../include/queue_stack.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(QueueStackTest, QueueIsCorrectlyEmptied)
{
	QueueStack queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	for (int i = 1; i <=4; i++)
		ASSERT_EQ(i, queue.pop());
}

TEST(QueueStackTest, ElementsAreCorrectlyPushedAndPoped)
{
	QueueStack queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	for (int i = 1; i <=2; i++)
		ASSERT_EQ(i, queue.pop());
	queue.push(5);
	queue.push(6);
	queue.push(7);
	for (int i = 3; i <=7; i++)
		ASSERT_EQ(i, queue.pop());
}