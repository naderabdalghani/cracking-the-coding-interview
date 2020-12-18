#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

template <class ItemType>
ItemType returnKthToLast(LinkedList<ItemType> L, int k) {
	if (L.getHead() == NULL)
		return NULL;
	Node<ItemType>* kthNode = L.getHead();
	Node<ItemType>* runnerNode = kthNode;
	while (runnerNode->getNext() != NULL && k != 0)
	{
		runnerNode = runnerNode->getNext();
		k--;
	}
	while (runnerNode->getNext() != NULL)
	{
		kthNode = kthNode->getNext();
		runnerNode = runnerNode->getNext();
	}
	return kthNode->getItem();
}


int main() {
	LinkedList<int> L;
	L.add(1);
	L.add(2);
	L.add(3);
	L.add(4);
	L.add(5);
	L.add(6);
	L.add(7);
	L.add(8);
	L.add(9);
	L.add(10);
	L.print();
	int k = 3;
	cout << k << "th to last element is " << returnKthToLast(L, k) << endl;
	return 0;
}
