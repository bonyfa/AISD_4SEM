#include <set.h>
#include <iostream>
#include <vector>

//default constructor
binary_tree::binary_tree() : _root(nullptr) {};
//create tree with 1 node
binary_tree::binary_tree(const int val) : _root(new node{ val, nullptr, nullptr }) {};


binary_tree& binary_tree::operator=(binary_tree other) {// not const binary_tree& because you need a copy of other
	swap(other);//swap copy and this
	return *this;
}

void binary_tree::swap(binary_tree& other) {
	std::swap(_root, other._root);//overload swap for operator= (copy and swap idiom)
}

node* binary_tree::copy(node* root) {//method needs for copy constructor
	//creates a deep copy of the binary tree by recursively creating new nodes and copying the left and right subtrees.
	if (!root) return nullptr;//if other == null then copy = null
	node* new_node = new node{ root->data, root->left, root->right };//else create a new node
	new_node->left = copy(root->left);//recusively copy left subtree
	new_node->right = copy(root->right);//right
	return new_node;//returns new tree root
}

binary_tree::binary_tree(const binary_tree& other) {//copy constructor
	_root = copy(other._root); //just create new root 
}

int binary_tree::get_root_value() {
	return _root->data;//need for tests
}

