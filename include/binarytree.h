#ifndef BINARY_TREE
#define BINARY_TREE

class BinaryTree {
public:
	int data;

	BinaryTree();
	BinaryTree(int item);
	BinaryTree* get_left_node();
	BinaryTree* get_right_node();
	BinaryTree* get_parent_node();
	void insert_at_left(int value);
	void insert_at_right(int value);
	void print_preorder();
	void print_inorder();
	void print_postorder();
	void print_breadthfirst();
	BinaryTree* next_inorder_node();
	bool is_binary_search_tree_preorder_approach();
	bool is_binary_search_tree_inorder_approach();
private:
	BinaryTree* left_node;
	BinaryTree* right_node;
	BinaryTree* parent_node;
	bool is_binary_search_tree_preorder_approach(int min, int max);
	bool is_binary_search_tree_inorder_approach(int min);
};

#endif
