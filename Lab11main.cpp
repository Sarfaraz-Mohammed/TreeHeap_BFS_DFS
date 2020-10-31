//============================================================================
// Name        : Lab11main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "treeheap.h"
using namespace std;

int main() {

	TreeHeap<int> tree;
	int input;

	cout << "Insert up to 20 elements in the tree heap: " << endl;
	for(int i = 0; i < 20; i++)
	{
		cin >> input;
		tree.insert(input);
	}
	tree.buildTreeHeap();

	cout << "Your tree: " << endl;
	tree.print();

	cout << "Search for an item: ";
	cin >> input;
	bTreeNode<int> bfs = tree.bfs(input);
	if(bfs == NULL)
	{
		cout << "Item can't be found in the tree." << endl;
	}else{
		cout << bfs << "Item found in the tree." << endl;
	}

	bTreeNode<int> dfs = tree.dfs(input);

	if(dfs == NULL)
	{
		cout << "Item can't be found in the tree." << endl;
	}else{
		cout << dfs << "Item found in the tree." << endl;
	}

	bTreeNode<int> search = tree.search(input);
	if(search == NULL)
	{
		cout << "Item can't be found in the tree." << endl;
	}else{
		cout << search << "Item found in the tree." << endl;
	}

	return 0;
}
