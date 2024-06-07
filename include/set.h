#include <vector>

struct node {
	int data;
	node* left;
	node* right;
};

class binary_tree {
	node* _root;

public:
	binary_tree();
	binary_tree(const int val);
	binary_tree(const binary_tree& other);

	void swap(binary_tree& other);
	binary_tree& operator=(binary_tree other);
	node* copy(node* root);
	bool equal(const node* first, const node* second);
	bool operator==(const binary_tree& second);
	bool contains(int key);
	bool insert(int key);
	bool _erase(node*& node_, int key);
	bool erase(int key);
	void _clear(node* root);
	void _print(const node* root);
	void print();
	void insert_in_vector(const node* other, std::vector<int>& vec);
	std::vector<int> to_vector();

	int get_root_value();

	~binary_tree();
};

std::vector<int> make_unique(std::vector<int> vector);