#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

template <class ItemType>
void deleteMiddleNode(Node<ItemType>* middleNode) {
	Node<ItemType>* followingNode = middleNode->getNext();
	middleNode->setItem(followingNode->getItem());
	middleNode->setNext(followingNode->getNext());
	delete followingNode;
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
	auto* nodeToBeDeleted = L.contains(4);
	deleteMiddleNode(nodeToBeDeleted);
	L.print();
	return 0;
}
