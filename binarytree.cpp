//Camille Copeland - File Name: binarytree.cpp - 05/07/2021

#include <iostream>
#include "binarytree.h"
#include "LL.h"
using namespace std;


binarytree::binarytree() {
	root = nullptr;
	mSize = 0;
}



binarytree::binarytree(const binarytree& copyMe) {
	copy(copyMe.root, root);
}



binarytree& binarytree::operator=(const binarytree& copyMe) {
	clear_aux(root);
	copy(copyMe.root, root);
	return *this;
}



void binarytree::copy(const treenode* copyMe, treenode*& trail) {
	if (copyMe == nullptr) {
		trail = nullptr;
	}
	else {
		trail = new treenode;
		trail->data = copyMe->data;
		copy(copyMe->left, trail->left);
		copy(copyMe->right, trail->right);
	}
}



binarytree::~binarytree() {
	clear_aux(root);
}



void binarytree::clear_aux(treenode* root) {
	if (root != nullptr) {
		clear_aux(root->left);
		clear_aux(root->right);
		delete root;
	}
}



void binarytree::print() const {
	print_aux(root);
}



void binarytree::insert(int item) {
	insert_aux(root, item);
	mSize++;
}



binarytree::size_type binarytree::size() const {
	return mSize;
}



int binarytree::find(int target, bool& found) const {
	return find_aux(root, target, found);
}



void binarytree::del(int target, bool& found) {
	del_aux(root, target, found);
	if (found) {
		mSize--;
	}
}



bool binarytree::prime(const int target) {
	for (int i = 2; i < target; i++) {
		if (target % i == 0) {
			return false;
		}
	}

	return true;
}



int binarytree::numPrimes() {
	return numPrimes_aux(root);
}



int binarytree::numPrimes_aux(const treenode* root) {
	int part = 0;

	if (root == nullptr) {
		return 0;
	}
	else if (prime(root->data)) {
		part = 1;
	}

	return numPrimes_aux(root->right) + numPrimes_aux(root->left) + part;
}



void binarytree::del_aux(treenode*& root, int target, bool& found) {
	if (root == nullptr) {
		found = false;
	}
	else if (target < root->data) {
		del_aux(root->left, target, found);
	}
	else if (target > root->data) {
		del_aux(root->right, target, found);
	}
	else if (root->left == nullptr) {		
		treenode* tempptr = root;
		root = root->right;
		delete tempptr;
		found = true;
	}
	else {		
		int max;
		remove_max(root->left, max);
		root->data = max;
		found = true;
	}
}



//pre: root != nullptr
void binarytree::remove_max(treenode*& root, int& max) {		
	if (root->right == nullptr) {
		max = root->data;
		treenode* tempptr = root;
		root = root->left;
		delete tempptr;
	}
	else {
		remove_max(root->right, max);
	}
}



int binarytree::find_aux(const treenode* root, int target, bool& found) {
	if (root == nullptr) {
		found = false;
		return 0;
	}
	else if (target == root->data) {
		found = true;
		return root->data;
	}
	else if (target < root->data) {
		return find_aux(root->left, target, found);
	}
	else {
		return find_aux(root->right, target, found);
	}
}



void binarytree::insert_aux(treenode*& root, int item) {
	if (root == nullptr) {
		root = new treenode;
		root->data = item;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (item <= root->data) {
		insert_aux(root->left, item);
	}
	else {
		insert_aux(root->right, item);
	}
}

LL<int> binarytree::toLL() {
	LL<int> list;
	convertLL(root, list);
	return list;
}

void binarytree::convertLL(const treenode* root, LL<int>& list) {
	if (root != nullptr) {
		convertLL(root->right, list);
		list.push_front(root->data);
		convertLL(root->left, list);
	}
}



void binarytree::print_aux(const treenode* root) {		
	if (root != nullptr) {
		print_aux(root->left);
		cout << root->data << " ";
		print_aux(root->right);
	}
}