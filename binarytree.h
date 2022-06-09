//Camille Copeland - File Name: binarytree.h - 05/07/2021

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "LL.h"
#include <cstdlib>

class binarytree
{
public:
	typedef std::size_t size_type;
	binarytree();
	binarytree(const binarytree& copyMe);
	binarytree& operator=(const binarytree& copyMe);
	~binarytree();
	int numPrimes();
	size_type size() const;
	void insert(int item);
	int find(int target, bool& found) const;
	void del(int target, bool& found);
	LL<int> toLL();
	void print() const;

private:
	struct treenode {
		int data;
		treenode* left;
		treenode* right;
	};
	size_type mSize;
	treenode* root;
	static void convertLL(const treenode* root, LL<int>& list);
	static void copy(const treenode* copyMe, treenode*& trail);
	static void clear_aux(treenode* root);
	static bool prime(const int target);
	static int numPrimes_aux(const treenode* root);
	static void insert_aux(treenode*& root, int item);
	static void print_aux(const treenode* root);
	static int find_aux(const treenode* root, int target, bool& found);
	static void del_aux(treenode*& root, int target, bool& found);
	static void remove_max(treenode*& root, int& max);
};
#endif

