#include <iostream>
#include "binarytree.h"
#include "LL.h"

using namespace std;

int main() {

	binarytree myTree;
	for (int i = 0; i < 20; i++) {
		myTree.insert(rand() % 50);
	}

	cout << "The binary tree: ";
	myTree.print();
	cout << endl;

	LL<int> myList;
	myList = myTree.toLL();

	cout << "The linked list: ";

	for (LL<int>::iterator i = myList.begin(); i != myList.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "The original binary tree still intact: ";
	myTree.print();

	cout << endl;

	binarytree list;

	int num;
	bool found;

	cout << "enter numer to insert (negative to quit): ";
	cin >> num;
	while (num >= 0) {
		list.insert(num);
		cout << "enter number to insert (negative to quit): ";
		cin >> num;
	}

	list.print();
	cout << endl;

	binarytree::size_type numItems;
	numItems = list.size();
	cout << "There are " << numItems << " items." << endl;

	cout << "enter a numer to find (negative to quit): ";
	cin >> num;
	while (num >= 0) {
		int result = list.find(num, found);
		if (!found) {
			cout << "not found" << endl;
		}
		else {
			cout << "found. The data is " << result << endl;
		}
		cout << "enter a number to find (negative to quit): ";
		cin >> num;
	}

	cout << "The number of primes in the tree is: " << list.numPrimes() << endl;

	cout << "enter a number to delete (negative to quit): ";
	cin >> num;
	while (num >= 0) {
		list.del(num, found);
		if (found) {
			cout << "the list is now ";
			list.print();
			cout << endl;
		}
		else {
			cout << num << " is not in the list." << endl;
		}
		cout << "enter a number to delete (negative to quit): ";
		cin >> num;
	}

	binarytree list2(list);
	
	cout << "Now list 2 should be a copy of list. Here it is: ";
	list2.print();
	cout << endl;

	list2.del(3, found);

	cout << "After delete at 3 from list2, list2 is now: ";
	list2.print();
	cout << endl << "list should be unchanged. Here it is: ";
	list.print();
	cout << endl;

	list = list2;

	cout << "Now list has been assigned list2 so it should match list2. Here it is: ";
	list.print();
	cout << endl;

	list.del(4, found);

	cout << "After delete at 4 from list, list is now: ";
	list.print();
	cout << endl << "list2 should be unchanged. Here it is: ";
	list2.print();
	cout << endl;
}