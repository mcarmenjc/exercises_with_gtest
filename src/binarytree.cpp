#include "../include/binarytree.h"
#include <iostream>
#include <string>
#include <queue>

BinaryTree::BinaryTree()
{
    this->left_node = NULL;
    this->right_node = NULL;
    this->parent_node = NULL;
}

BinaryTree::BinaryTree(int item)
{
    this->data = item;
    this->left_node = NULL;
    this->right_node = NULL;
    this->parent_node = NULL;
}

BinaryTree* BinaryTree::get_left_node()
{
    return this->left_node;
}

BinaryTree* BinaryTree::get_right_node()
{
    return this->right_node;
}

BinaryTree* BinaryTree::get_parent_node()
{
    return this->parent_node;
}

void BinaryTree::insert_at_left(int value)
{
    BinaryTree* new_node = new BinaryTree(value);
    new_node->parent_node = this;
    this->left_node = new_node;
}

void BinaryTree::insert_at_right(int value)
{
    BinaryTree* new_node = new BinaryTree(value);
    new_node->parent_node = this;
    this->right_node = new_node;
}

void BinaryTree::print_preorder()
{
    std::cout << this->data << "\t";
    if (this->left_node != NULL)
        this->left_node->print_preorder();
    if (this->right_node != NULL)
        this->right_node->print_preorder();
}

void BinaryTree::print_inorder()
{
    if (this->left_node != NULL)
        this->left_node->print_preorder();
    std::cout << this->data << "\t";
    if (this->right_node != NULL)
        this->right_node->print_preorder();
}

void BinaryTree::print_postorder()
{
    if (this->left_node != NULL)
        this->left_node->print_preorder();
    if (this->right_node != NULL)
        this->right_node->print_preorder();
    std::cout << this->data << "\t";
}

void BinaryTree::print_breadthfirst()
{
    std::queue<BinaryTree*> breadth_first;
    breadth_first.push(this);

    while (!breadth_first.empty())
    {
        BinaryTree* node = breadth_first.front();
        breadth_first.pop();
        std::cout << node->data << "\t";
        if (node->left_node != NULL)
            breadth_first.push(node->left_node);
        if (node->right_node != NULL)
            breadth_first.push(node->right_node);
    }
}

BinaryTree* BinaryTree::next_inorder_node()
{
    if (this->right_node != NULL)
    {
        BinaryTree* node = this->right_node;
        while (node->left_node != NULL)
            node = node->left_node;
        return node;
    }
    else
    {
        BinaryTree* parent = this->parent_node;
        BinaryTree* node = this;
        while (parent != NULL && parent->right_node == node)
        {
            node = parent;
            parent = parent->parent_node;
        }

        return parent;
    }

    return NULL;
}

bool BinaryTree::is_binary_search_tree_preorder_approach()
{
    if (this == NULL)
        return false;
    return is_binary_search_tree_preorder_approach(-1000000, 1000000);
}

bool BinaryTree::is_binary_search_tree_preorder_approach(int min, int max)
{
    if (this == NULL)
        return true;

    if (this->data < min || this->data > max)
        return false;

    return this->left_node->is_binary_search_tree_preorder_approach(min, this->data) && this->right_node->is_binary_search_tree_preorder_approach(this->data, max);
}

bool BinaryTree::is_binary_search_tree_inorder_approach()
{
    if (this == NULL)
        return false;
    return is_binary_search_tree_inorder_approach(-1000000);
}

bool BinaryTree::is_binary_search_tree_inorder_approach(int min)
{
    if (this == NULL)
        return true;

    return this->left_node->is_binary_search_tree_inorder_approach(min) && this->data >= min && this->right_node->is_binary_search_tree_inorder_approach(this->data);
}