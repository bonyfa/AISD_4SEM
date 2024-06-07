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
bool binary_tree::contains(int key) {
	//since we have a search tree, the right side contains elements that are larger than the current one
	//and on the left - smaller
	node* tmp = _root;
	while (tmp) {//while root exists
		if (tmp->data == key) return true;//found
		if (tmp->data > key) {//if current value larger than key. look for in left subtree
			tmp = tmp->left;
		}
		else tmp = tmp->right;
	}
	return false;
}


bool binary_tree::insert(int key) {
	auto new_node = new node{ key, nullptr, nullptr };
	//replace head if head is null
	if (!_root) {
		_root = new_node;
		return true;
	}
	node* tmp = _root;

	while (tmp) {//while root exist try to find position for insert
		//if there is such a node, then we dont insert
		if (tmp->data == key) return false;
		//else find position for insert
		if (tmp->data > key) {//if current value larger than key. look for in left subtree
			if (!tmp->left) {//if node=nullptr insert new value
				tmp->left = new_node;
				return true;
			}
			tmp = tmp->left;
		}
		else {//search in right subtree
			if (!tmp->right) {//if node=nullptr insert new value
				tmp->right = new_node;
				return true;
			}
			tmp = tmp->right;
		}
	}
	return false;
}


bool binary_tree::erase(int key) {
	return _erase(_root, key);
}

bool binary_tree::_erase(node*& node_, int key) {//recursive _erase needs for erase
	if (!node_) {//if root is not exist return false....
		return false;
	}
	// If the key is less than current node's data, 
	//recursively call _erase on the left subtree.
	if (key < node_->data) {
		return _erase(node_->left, key);
	}
	// If the key is greater than current node's data,
	//recursively call _erase on the right subtree.
	else if (key > node_->data) {
		return _erase(node_->right, key);
	}
	else {
		if (!node_->left) {//if only right child -> replace deleted node with the right child
			auto tmp = node_->right;
			delete node_;
			node_ = tmp;
			return true;
		}
		else if (!node_->right) {//if only left child -> replace deleted node with the left child
			auto tmp = node_->left;
			delete node_;
			node_ = tmp;
			return true;
		}
		// If the current node has both left and right children.
		auto min_right = node_->right;
		while (min_right->left) {
			// Find the minimum node in the right subtree.
			min_right = min_right->left;
		}
		// Replace the current node's data with the data of the minimum node in the right subtree.
		node_->data = min_right->data;
		// Recursively call _erase to remove the minimum node from the right subtree.
		return _erase(node_->right, min_right->data);
	}
}

bool binary_tree::equal(const node* first, const node* second) {//needs for operator==
	//params: first tree`s root and second`s root
	if (!first && !second) return true;//if both null 
	if (first && second) {//if both exists
		//check current data and recursively check left and right subtrees
		return first->data == second->data && equal(first->left, second->left) && equal(first->right, second->right);
	}
	return false;
}


void binary_tree::_clear(node* root) {//needs for destructor
	if (!root) return;//if root not exist return
	_clear(root->left);//recursively delete left subtree
	_clear(root->right);//right
	delete root;
}

binary_tree::~binary_tree() {
	_clear(_root);
	_root = nullptr;
}

void binary_tree::_print(const node* root) {//recursive _print needs for print
	//root -> left -> right
	if (!root) return;
	std::cout << root->data << " ";
	_print(root->left);
	_print(root->right);
}

void binary_tree::print() {//print root->left->right
	_print(_root);
}

bool binary_tree::operator==(const binary_tree& second) {
	return equal(_root, second._root);
}

void binary_tree::insert_in_vector(const node* other, std::vector<int>& vec) {//insert values in vector(left->root->right)
	if (!other) {
		return;
	}
	insert_in_vector(other->left, vec);
	vec.push_back(other->data);
	insert_in_vector(other->right, vec);
}

std::vector<int> binary_tree::to_vector() {
	std::vector <int> convert;
	insert_in_vector(_root, convert);
	return convert;
}

std::vector<int> make_unique(std::vector<int> vector) {//we add the vector values 
	//to the tree (there are only unique values in the tree) then we again convert the tree into a vector
	if (vector.empty())
		throw std::runtime_error("vector is empty");
	std::vector<int> result;
	binary_tree tree(vector[0]);
	for (size_t i = 1; i < vector.size(); ++i) {
		tree.insert(vector[i]);
	}
	result = tree.to_vector();
	return result;
}
