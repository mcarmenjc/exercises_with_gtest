#include "../include/queue_stack.h"

void QueueStack::push(int value)
{
	queue.push(value);
}

int QueueStack::pop()
{
	if (dequeue.empty())
	{
		dequeue_stack();
	}

	int value = dequeue.top();
	dequeue.pop();
	return value;
}

void QueueStack::dequeue_stack()
{
	while (!queue.empty())
	{
		dequeue.push(queue.top());
		queue.pop();
	}
}