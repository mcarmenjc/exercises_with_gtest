#include "../include/stack_queue.h"
#include <iostream>

void StackQueue::push(int value)
{
	if (second_queue.empty())
	{
		first_queue.push(value);
	}
	else
	{
		second_queue.push(value);
	}
}

int StackQueue::pop()
{
	int value;

	if (!first_queue.empty())
	{	
		value = get_last_element_from_queue(first_queue, second_queue);
	}
	else
	{	
		value = get_last_element_from_queue(second_queue, first_queue);
	}

	return value;
}

void StackQueue::copy_queue(std::queue<int> &non_empty_queue, std::queue<int> &empty_queue)
{
	while (non_empty_queue.size() > 1)
	{
		int value = non_empty_queue.front();
		non_empty_queue.pop();
		empty_queue.push(value);
	}
}

int StackQueue::get_last_element_from_queue(std::queue<int> &non_empty_queue, std::queue<int> &empty_queue)
{
	copy_queue(non_empty_queue, empty_queue);
	int value = non_empty_queue.front();
	non_empty_queue.pop();
	return value;
}