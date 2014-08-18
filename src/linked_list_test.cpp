#include "../include/linked_list.h"
#include "gtest/gtest.h"
#include <iostream>

class LinkedListTest : public ::testing::Test {
protected:
	virtual void SetUp()
	{
		LinkedList* next = first_list_to_sort;
		next->insert_after(5);
		next = next->next_node();
		next->insert_after(3);
		next = next->next_node();
		next->insert_after(2);
		next = next->next_node();
		next->insert_after(4);

		next = second_list_to_sort;
		next->insert_after(1);
		next = next->next_node();
		next->insert_after(5);
		next = next->next_node();
		next->insert_after(3);
		next = next->next_node();
		next->insert_after(3);
		next = next->next_node();
		next->insert_after(2);
		next = next->next_node();
		next->insert_after(4);
		next = next->next_node();
		next->insert_after(2);
		next = next->next_node();
		next->insert_after(7);
		next = next->next_node();
		next->insert_after(5);

		next = first_list_to_merge;
		next->insert_after(3);
		next = next->next_node();
		next->insert_after(5);
		next = next->next_node();
		next->insert_after(7);
		
		next = second_list_to_merge;
		next->insert_after(4);
		next = next->next_node();
		next->insert_after(6);
		next = next->next_node();
		next->insert_after(8);

		next = list_with_loop;
		next->insert_after(2);
		next = next->next_node();
		next->insert_after(3);
		next = next->next_node();
		LinkedList* loop_node = next;
		next->insert_after(4);
		next = next->next_node();
		next->insert_after(5);
		next = next->next_node();
		next->insert_after(6);
		next = next->next_node();
		next->set_next_node(loop_node);
	}

	LinkedList* first_list_to_sort = new LinkedList(1);
	LinkedList* second_list_to_sort = new LinkedList(1);
	LinkedList* first_list_to_merge = new LinkedList(1);
	LinkedList* second_list_to_merge = new LinkedList(2);
	LinkedList* list_with_loop = new LinkedList(1);
};

TEST_F(LinkedListTest, LinkedListIsCorrectlySorted)
{
	first_list_to_sort->sort_list();
	LinkedList* actual_node = first_list_to_sort;
	int i = 1;
	while (actual_node != NULL)
	{
		ASSERT_EQ(i, actual_node->data);
		i++;
		actual_node = actual_node->next_node();
	}
}

TEST_F(LinkedListTest, LinkedListIsCorrectlySortedWithRepeatedElements)
{
	second_list_to_sort->sort_list();
	LinkedList* actual_node = second_list_to_sort;
	ASSERT_EQ(1, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(1, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(2, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(2, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(3, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(3, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(4, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(5, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(5, actual_node->data);
	actual_node = actual_node->next_node();
	ASSERT_EQ(7, actual_node->data);
}

TEST_F(LinkedListTest, TwoOrederedListsAreCorrectlyMerged)
{
	LinkedList* merged_list = first_list_to_merge->merge(second_list_to_merge);
	LinkedList* actual_node = merged_list;
	int i = 1;
	while (actual_node != NULL)
	{
		ASSERT_EQ(i, actual_node->data);
		i++;
		actual_node = actual_node->next_node();
	}
}

TEST_F(LinkedListTest, TwoOrederedListsAreCorrectlyMergedWithRepeatedValues)
{
	first_list_to_sort->sort_list();
	LinkedList* merged_list = first_list_to_merge->merge(first_list_to_sort);
	LinkedList* actual_node = merged_list;
	ASSERT_EQ(1, actual_node->data);
	actual_node = actual_node->next_node();	
	ASSERT_EQ(1, actual_node->data);
	actual_node = actual_node->next_node();	
	ASSERT_EQ(2, actual_node->data);
	actual_node = actual_node->next_node();	
	ASSERT_EQ(3, actual_node->data);
	actual_node = actual_node->next_node();	
	ASSERT_EQ(3, actual_node->data);
	actual_node = actual_node->next_node();	
	ASSERT_EQ(4, actual_node->data);
	actual_node = actual_node->next_node();	
	ASSERT_EQ(5, actual_node->data);
	actual_node = actual_node->next_node();	
	ASSERT_EQ(5, actual_node->data);
	actual_node = actual_node->next_node();	
	ASSERT_EQ(7, actual_node->data);
}

TEST_F(LinkedListTest, ListWithNoLoop)
{
	bool loop = first_list_to_sort->has_loop();
	ASSERT_FALSE(loop);
}

TEST_F(LinkedListTest, ListWithLoop)
{
	bool loop = list_with_loop->has_loop();
	ASSERT_TRUE(loop);
}

TEST_F(LinkedListTest, LoopEntryNodeIsCorrectlyObtained)
{
	LinkedList* entry_loop_node = list_with_loop->get_entry_loop_node();
	ASSERT_EQ(3, entry_loop_node->data);
}