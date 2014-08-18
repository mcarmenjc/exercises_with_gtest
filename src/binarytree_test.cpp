#include "../include/binarytree.h"
#include "gtest/gtest.h"
#include <iostream>

class BinaryTreeTest : public ::testing::Test {
protected:
	virtual void SetUp()
	{
		tree = new BinaryTree();
		tree->data = 10;
		tree->insert_at_left(6);
		tree->insert_at_right(14);
		BinaryTree* node = tree->get_left_node();
		node->insert_at_left(4);
		node->insert_at_right(8);
		node = tree->get_right_node();
		node->insert_at_left(12);
		node->insert_at_right(16);

		not_bst = new BinaryTree();
		not_bst->data = 10;
		not_bst->insert_at_left(6);
		not_bst->insert_at_right(5);
		node = not_bst->get_left_node();
		node->insert_at_left(4);
		node->insert_at_right(8);
		node = not_bst->get_right_node();
		node->insert_at_left(12);
		node->insert_at_right(16);
	}

	BinaryTree* tree;
	BinaryTree* not_bst;
};

TEST_F(BinaryTreeTest, NextInOrderNodeWhenNodeAtMostLeft)
{
	BinaryTree* actual_node = tree->get_left_node()->get_left_node();
	BinaryTree* next_node = actual_node->next_inorder_node();
	ASSERT_EQ(6, next_node->data);
}

TEST_F(BinaryTreeTest, NextInOrderNodeWhenNodeAtRight)
{
	BinaryTree* actual_node = tree->get_left_node()->get_right_node();
	BinaryTree* next_node = actual_node->next_inorder_node();
	ASSERT_EQ(10, next_node->data);
}

TEST_F(BinaryTreeTest, NextInOrderNodeWhenNodeAtRightAndHasChildren)
{
	BinaryTree* actual_node = tree->get_right_node();
	BinaryTree* next_node = actual_node->next_inorder_node();
	ASSERT_EQ(16, next_node->data);
}

TEST_F(BinaryTreeTest, NextInOrderNodeWhenNodeAtMostRight)
{
	BinaryTree* actual_node = tree->get_right_node()->get_right_node();
	BinaryTree* next_node = actual_node->next_inorder_node();
	ASSERT_EQ(NULL, next_node);
}

TEST_F(BinaryTreeTest, BinarySearchTreeIsCorrectlyDetectedWithPreorderApproach)
{
	bool is_BST = tree->is_binary_search_tree_preorder_approach();
	ASSERT_TRUE(is_BST);
}

TEST_F(BinaryTreeTest, BinaryTreeRecognisedAsNotBinarySearchTreeWithPreorderApproach)
{
	bool is_BST = not_bst->is_binary_search_tree_preorder_approach();
	ASSERT_FALSE(is_BST);
}

TEST_F(BinaryTreeTest, BinarySearchTreeIsCorrectlyDetectedWithInorderApproach)
{
	bool is_BST = tree->is_binary_search_tree_inorder_approach();
	ASSERT_TRUE(is_BST);
}

TEST_F(BinaryTreeTest, BinaryTreeRecognisedAsNotBinarySearchTreeWithInorderApproach)
{
	bool is_BST = not_bst->is_binary_search_tree_inorder_approach();
	ASSERT_FALSE(is_BST);
}