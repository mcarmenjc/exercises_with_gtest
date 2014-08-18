#ifndef QUEUE_STACK
#define QUEUE_STACK

#include <stack>

class QueueStack {
public:
	void push(int value);
	int pop();
private:
	std::stack<int> queue;
	std::stack<int> dequeue;
	void dequeue_stack();
};

#endif
