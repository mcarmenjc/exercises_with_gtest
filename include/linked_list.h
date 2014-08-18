#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

class LinkedList {
public:
	LinkedList();
	LinkedList(int item);
	int data;
	LinkedList* next_node();
	void insert_after(int value);
	void set_next_node(LinkedList* next_node);
	LinkedList* delete_after();
	void push(int value);
	LinkedList* get_node_at(int position);
	void reverse_print();
	void print();
	void sort_list();
	void exchange_nodes(LinkedList* first_node, LinkedList* second_node);
	LinkedList* merge(LinkedList* other_list);
	void copy_nodes(LinkedList* node);
	bool has_loop();
	LinkedList* get_entry_loop_node();
private:
	LinkedList * next;
	LinkedList* get_meeting_node();
	int get_number_of_nodes_in_loop();
};

#endif
