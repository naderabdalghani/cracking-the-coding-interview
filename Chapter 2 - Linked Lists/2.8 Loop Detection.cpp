#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;


Node<int>* detectLoopBeginning(LinkedList<int> L) {
	if (L.getHead() == NULL) {
		return NULL;
	}
	Node<int>* slow = L.getHead();
	Node<int>* fast = L.getHead();
	do
	{
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
	} while (slow != fast);
	slow = L.getHead();
	while (slow != fast)
	{
		slow = slow->getNext();
		fast = fast->getNext();
	}
	return slow;
}


int main() {
	LinkedList<int> L1;
	L1.add(1);
	L1.add(0);

	Node<int>* n1 = new Node<int>(2);
	Node<int>* n2 = new Node<int>(3);
	Node<int>* n3 = new Node<int>(4);
	n1->setNext(n2);
	n2->setNext(n3);
	n3->setNext(n1);

	L1.addToTail(n1);

	Node<int>* loopBeginning = detectLoopBeginning(L1);
	if (loopBeginning) {
		cout << "L1 has a loop that starts at " << loopBeginning->getItem() << endl;
	}
	else {
		cout << "L1 is empty" << endl;
	}
	return 0;
}
