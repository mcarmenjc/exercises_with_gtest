#ifndef STACK_QUEUE
#define STACK_QUEUE

#include <queue>

class StackQueue {
public:
	void push(int value);
	int pop();
private:
	std::queue<int> first_queue;
	std::queue<int> second_queue;
	void copy_queue(std::queue<int> &non_empty_queue, std::queue<int> &empty_queue);
	int get_last_element_from_queue(std::queue<int> &non_empty_queue, std::queue<int> &empty_queue);
};

#endif
