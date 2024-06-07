#include <set.h>
#include <gtest/gtest.h>
#include<iostream>

TEST(tree_test, constructor_params) {
	binary_tree bt{ 1 };
	ASSERT_EQ(bt.get_root_value(), 1);
}

TEST(tree_test, overloaded_equal) {
	binary_tree set2(1);
	binary_tree set1 = set2;
	ASSERT_TRUE(set1 == set2);
}

TEST(tree_test, copy_constructor) {
	binary_tree bt(1);
	binary_tree copy(bt);
	ASSERT_TRUE(copy == bt);
}

TEST(tree_test, contains) {
	binary_tree bt(1);
	ASSERT_TRUE(bt.contains(1));
}

TEST(tree_test, insert) {
	binary_tree bt(1);
	bt.insert(2);
	ASSERT_TRUE(bt.contains(2));
}

TEST(tree_test, erase_item_in_tail) {
	binary_tree bt(1);
	bt.insert(9);
	bt.insert(4);
	bt.erase(4);
	binary_tree bt1(1);
	bt1.insert(9);
	ASSERT_TRUE(bt == bt1);
}

TEST(tree_test, erase_item_in_middle) {
	binary_tree bt(1);
	bt.insert(9);
	bt.insert(4);
	bt.erase(9);
	binary_tree bt1(1);
	bt1.insert(4);
	ASSERT_TRUE(bt == bt1);
}

TEST(tree_test, erase_item_in_head) {
	binary_tree bt(1);
	bt.insert(9);
	bt.insert(4);
	bt.erase(1);
	binary_tree bt1(9);
	bt1.insert(4);
	ASSERT_TRUE(bt == bt1);
}

TEST(task_test, make_uni_vector) {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	std::vector<int> unique = make_unique(vec);
	std::vector<int> result;
	result.push_back(1);
	result.push_back(2);
	ASSERT_TRUE(unique == result);
}
