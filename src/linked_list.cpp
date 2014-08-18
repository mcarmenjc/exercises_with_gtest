#include "../include/linked_list.h"
#include <iostream>
#include <string>

LinkedList::LinkedList()
{
}

LinkedList::LinkedList(int item)
{
    this->data = item;
    this->next = NULL;
}


LinkedList* LinkedList::next_node()
{
    return this->next;
}

void LinkedList::insert_after(int value)
{
    LinkedList* new_node = new LinkedList(value);
    new_node->next = this->next;
    this->next = new_node;
}

void LinkedList::set_next_node(LinkedList* next_node)
{
    this->next = next_node;
}

LinkedList* LinkedList::delete_after()
{
    LinkedList* temp_node = next;
    if(next != NULL)
        next = next->next;
    return temp_node;
}

void LinkedList::push(int value)
{
    LinkedList* new_node = new LinkedList(value);
    LinkedList* tail = this->next;
    while (tail->next!=NULL)
        tail = tail->next;
    tail->next = new_node;
}

LinkedList* LinkedList::get_node_at(int position)
{
    LinkedList* node_iterator = this;
    for (int i = 0; i < position && node_iterator != NULL; i++)
        node_iterator = node_iterator->next;
    return node_iterator;
}

void LinkedList::reverse_print()
{
    if (this->next != NULL)
        this->next->reverse_print();
    std::cout << this->data << std::endl;
}

void LinkedList::print()
{
    LinkedList* actual_node = this;
    
    while(actual_node != NULL)
    {
        std::cout << actual_node->data << " -> ";
        actual_node = actual_node->next;
    }
    std::cout << std::endl;
}

void LinkedList::sort_list()
{
    if (this->next == NULL)
        return;
    LinkedList * tail = this;
    LinkedList * node_to_sort = this->next;

    while (node_to_sort != NULL)
    {
        LinkedList * node = this;
        while (node != NULL && node->next != node_to_sort && node->next->data <= node_to_sort->data)
        {
            node = node->next;
        }

        if (node->next->data > node_to_sort->data)
        {
            tail->next = node_to_sort->next;
            exchange_nodes(node, node_to_sort);
        }
        else
            tail = tail->next;

        node_to_sort = tail->next;
    }
}

void LinkedList::exchange_nodes(LinkedList* first_node, LinkedList* second_node)
{
    LinkedList * aux_node = first_node->next;
    first_node->next = second_node;
    second_node->next = aux_node;
}

LinkedList* LinkedList::merge(LinkedList* other_list)
{
    LinkedList* node = this;
    LinkedList* other_node = other_list;
    LinkedList* result_list;

    if (node->data < other_node->data)
    {
        result_list = new LinkedList(node->data);
        node = node->next;
    }
    else
    {
        result_list = new LinkedList(other_node->data);
        other_node = other_node->next;
    }

    LinkedList* result_node = result_list;

    while (node != NULL && other_node != NULL)
    {
        if (node->data < other_node->data)
        {
            result_node->next = new LinkedList(node->data);
            node = node->next;
        }
        else
        {
            result_node->next = new LinkedList(other_node->data);
            other_node = other_node->next;
        }

        result_node = result_node->next;
    }
    result_node->copy_nodes(node);
    result_node->copy_nodes(other_node);

    return result_list;
}

void LinkedList::copy_nodes(LinkedList* node)
{
    LinkedList *actual_node = this;
    while (node != NULL)
    {
        actual_node->next = new LinkedList(node->data);
        node = node->next;
        actual_node = actual_node->next;
    }
}
bool LinkedList::has_loop()
{
    LinkedList* slow_node = this->next;
    LinkedList* fast_node = slow_node->next;

    while (slow_node != NULL && fast_node != NULL)
    {
        if (slow_node == fast_node)
            return true;
        slow_node = slow_node->next;
        fast_node = fast_node->next;
        if (fast_node != NULL)
            fast_node = fast_node->next;
    }

    return false;
}

LinkedList* LinkedList::get_meeting_node()
{
    LinkedList* slow_node = this->next;
    LinkedList* fast_node = slow_node->next;

    while (slow_node != NULL && fast_node != NULL)
    {
        if (slow_node == fast_node)
            return slow_node;
        slow_node = slow_node->next;
        fast_node = fast_node->next;
        if (fast_node != NULL)
            fast_node = fast_node->next;
    }

    return NULL;
}

int LinkedList::get_number_of_nodes_in_loop()
{
    LinkedList* meeting_node = get_meeting_node();
    LinkedList* node_iterator = meeting_node->next;
    int counter = 1;
    while(node_iterator != meeting_node)
    {
        counter ++;
        node_iterator = node_iterator->next;
    }
    return counter;
}

LinkedList* LinkedList::get_entry_loop_node()
{
    int nodes_in_loop = get_number_of_nodes_in_loop();
    LinkedList* slow_node = this;
    LinkedList* fast_node = get_node_at(nodes_in_loop);
    while (slow_node != fast_node)
    {
        slow_node = slow_node->next;
        fast_node = fast_node->next;
    }

    return slow_node;
}