#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <set>

using namespace std;

template <class ItemType>
void removeDups(LinkedList<ItemType> &L) {
	set<ItemType> elements;
	Node<ItemType>* prevNode = NULL;
	Node<ItemType>* currNode = L.getHead();
	while (currNode != NULL) {
		if(elements.find(currNode->getItem()) != elements.end()) {
			prevNode->setNext(currNode->getNext());
			delete currNode;
			currNode = prevNode->getNext();
		}
		else {
			elements.insert(currNode->getItem());
			prevNode = currNode;
			currNode = currNode->getNext();
		}
	}
}


int main() {
	LinkedList<int> L;
	L.add(3);
	L.add(3);
	L.add(3);
	L.add(3);
	L.add(3);
	/*L.add(2);
	L.add(7);
	L.add(8);
	L.add(3);
	L.add(4);
	L.add(8);
	L.add(2);
	L.add(1);
	L.add(3);*/
	L.print();
	removeDups(L);
	L.print();
	return 0;
}
