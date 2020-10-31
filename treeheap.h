/*
 * treeheap.h
 *
 *  Created on: May 3, 2019
 *      Author: smohammed730
 */

#ifndef TREEHEAP_H_
#define TREEHEAP_H_

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class elemType>
struct bTreeNode{
	elemType info;
	bTreeNode<elemType> *leftLink;
	bTreeNode<elemType> *rightLink;
};

template <class elemType>
class TreeHeap{
private:
	int size;
	int maxSize;
	elemType* array;
	void heapify(int lower,int higher);
	void heapSort();
	void buildHeap();
	bTreeNode<elemType> *root;
	bTreeNode<elemType> *tail;
public:
	TreeHeap();
	~TreeHeap();
	void print(bTreeNode<elemType> *node) const;
	void insert(elemType);
	void treeInsert(const elemType&);
	void buildTreeHeap(int index, bTreeNode<elemType>* current);
	const bTreeNode<elemType>* dfs(elemType);
	const bTreeNode<elemType>* bfs(elemType);
	const bTreeNode<elemType>* search(elemType item, bTreeNode<elemType> *current);
};

//constructor
template <class elemType>
TreeHeap<elemType>::TreeHeap()
{
	size = 0;
	maxSize = 0;
	array = new elemType[20];
	root = NULL;
	tail = NULL;
}

//destructor
template <class elemType>
TreeHeap<elemType>::~TreeHeap()
{
	delete root;
	delete tail;
	delete[] array;
}

//print
template <class elemType>
void TreeHeap<elemType>::print(bTreeNode<elemType> *node) const
{
	if(node != NULL)
	{
		cout << node->info <<" "<<endl;
		print(node->leftLink);
		print(node->rightLink);
	}
	print(root);
}


// insert
template <class elemType>
void TreeHeap<elemType>::insert(elemType item)
{
	array[size] = item;
	size++;
	buildHeap();
}


//buildHeap
template <class elemType>
void TreeHeap<elemType>::buildHeap()
{
	for(int i = size/2 - 1; i >= 0; i--)
	{
		heapify(i, size - 1);
	}
}

//heapify
template <class elemType>
void TreeHeap<elemType>::heapify(int lower, int higher)
{
	int index;
	elemType temp = array[lower];
	index = 2 * lower + 1;
	while(index <= higher)
	{
		if(index < higher)
		{
			if(array[index] < array[index + 1])
			{
				index = index + 1;
			}
		}
		if(temp > array[index])
		{
			break;
		}else{
			array[lower] = array[index];
			lower = index;
			index = 2 * lower + 1;
		}

	}
	array[lower] = temp;
}

//heap sort
template <class elemType>
void TreeHeap<elemType>::heapSort()
{
	elemType temp;
	buildHeap();
	for(int j = size - 1; j >= 0; j--)
	{
		temp = array[j];
		array[j] = array[0];
		array[0] = temp;
		heapify(0, j - 1);
	}
}

//build tree heap
template <class elemType>
void TreeHeap<elemType>::buildTreeHeap(int index, bTreeNode<elemType>* current)
{
	if(index >= size)
	{
		return;
	}

	if(current == root)
	{
		root = new bTreeNode<elemType>;
		root->info = array[index];
		current = root;
	}

	if(2 * index + 1 < size)
	{
		bTreeNode<elemType> *lChild;
		lChild = new bTreeNode<elemType>;

		lChild->info = array[2 * index + 1];
		current->leftLink = lChild;
		buildTreeHeap(2 * index + 1, lChild);
	}

	if(2 * index + 2 < size)
	{
		bTreeNode<elemType> *rChild;
		rChild = new bTreeNode<elemType>;

		rChild->info = array[2 * index + 2];
		current->rightLink = rChild;
		buildTreeHeap(2 * index + 2, rChild);

	}
	buildTreeHeap(0, root);
}



//tree insert
template <class elemType>
void TreeHeap<elemType>::treeInsert(const elemType& item)
{
	bTreeNode<elemType> *current;
	bTreeNode<elemType> *next;
	bTreeNode<elemType> *node2;

	node2 = new bTreeNode<elemType>;
	assert(node2 != NULL);

	node2->info = item;
	node2->leftLink = NULL;
	node2->rightLink = NULL;

	if(root == NULL)
	{
		root = node2;
	}

	current = root;
	while(current != NULL)
	{
		next = current;
		if(current->info == item)
		{
			cout << "Same element can't be entered into the tree twice." <<endl;
		}

		if(current->info > item)
		{
			current = current->leftLink;
		}else
		{
			current = current->rightLink;
		}
	}

	if(next->info > item)
	{
		next->leftLink = node2;
	}

	next->rightLink = node2;

}

//bfs
template <class elemType>
const bTreeNode<elemType>* TreeHeap<elemType>::bfs(elemType item)
{
	queue<bTreeNode<elemType>*> queue;
	queue.enqueue(root);

	while(!queue.empty())
	{
		bTreeNode<elemType>* a = queue.front();
		if(a->leftLink)
		{
			queue.enqueue(a->leftLink);
		}
		if(a->rightLink)
		{
			queue.enqueue(a->rightLink);
		}
		if(a->info == item)
		{
			return a;
		}
	}
	return NULL;
}

//dfs
template <class elemType>
const bTreeNode<elemType>* TreeHeap<elemType>::dfs(elemType item)
{
	stack<bTreeNode<elemType>*> stack;
	stack.push(root);

	while(!stack.empty())
	{
		bTreeNode<elemType>* a = stack.top();
		stack.pop();
		if(a->leftLink)
		{
			stack.push(a->leftLink);
		}
		if(a->rightLink)
		{
			stack.push(a->rightLink);
		}
		if(a->info == item)
		{
			return a;
		}
	}
	return NULL;
}

//search
template <class elemType>
const bTreeNode<elemType>* TreeHeap<elemType>::search(elemType item, bTreeNode<elemType> *current)
{
	if(current != NULL)
	{
		if(current->info == item)
		{
			return current;
		}
		search(item, current->leftLink);
		search(item, current->rightLink);
	}
	search(item, root);
}


#endif /* TREEHEAP_H_ */
