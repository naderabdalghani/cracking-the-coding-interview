#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

template <class ItemType>
void partition(LinkedList<ItemType> &L, ItemType pivot) {
	if (L.getHead() == NULL)
		return;
	auto* prevNode = L.getHead();
	auto* currNode = prevNode->getNext();
	bool moveLesserNode = false;
	while (currNode != NULL)
	{
		if (prevNode->getItem() >= pivot && !moveLesserNode) {
			moveLesserNode = true;
		}
		if (currNode->getItem() < pivot && moveLesserNode) {
			L.add(currNode->getItem());
			prevNode->setNext(currNode->getNext());
			delete currNode;
			currNode = prevNode->getNext();
		}
		else {
			prevNode = prevNode->getNext();
			currNode = currNode->getNext();
		}
	}
}


int main() {
	LinkedList<int> L;
	L.add(1);
	L.add(2);
	L.add(10);
	L.add(5);
	L.add(8);
	L.add(5);
	L.add(3);
	L.print();
	partition(L, 5);
	L.print();
	return 0;
}
