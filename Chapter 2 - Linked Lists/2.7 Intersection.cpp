#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;


Node<int>* intersects(LinkedList<int> l1, LinkedList<int> l2) {
	Node<int>* head1, * head2;
	head1 = l1.getHead();
	head2 = l2.getHead();
	int l1Size = 0, l2Size = 0;
	while (head1 != NULL) {
		l1Size++;
		if (head1->getNext() == NULL) {
			break;
		}
		head1 = head1->getNext();
	}
	while (head2 != NULL) {
		l2Size++;
		if (head2->getNext() == NULL) {
			break;
		}
		head2 = head2->getNext();
	}
	if (l1Size == 0 || l2Size == 0 || head1 != head2) {
		return NULL;
	}
	int sizeDifference = abs(l1Size - l2Size);
	head1 = l1.getHead();
	head2 = l2.getHead();
	if (l1Size > l2Size)
	{
		for (int i = 0; i < sizeDifference; i++)
		{
			head1 = head1->getNext();
		}
	}
	else if (l1Size < l2Size) {
		for (int i = 0; i < sizeDifference; i++)
		{
			head2 = head2->getNext();
		}
	}
	while (head1 != NULL)
	{
		if (head1 == head2)
			return head1;
		head1 = head1->getNext();
		head2 = head2->getNext();
	}
	return NULL;
}


int main() {
	LinkedList<int> L1, L2, L3;
	L1.add(4);
	L1.add(3);
	L1.add(2);
	L1.add(1);

	L2.add(33);
	L2.add(22);
	L2.add(11);

	Node<int>* n1 = new Node<int>(5);
	Node<int>* n2 = new Node<int>(6);
	Node<int>* n3 = new Node<int>(7);
	n2->setNext(n3);
	n1->setNext(n2);

	L1.addToTail(n1);
	L2.addToTail(n1);


	L3.add(111);
	L3.add(222);
	L3.add(333);
	L3.add(444);
	L3.add(555);
	L3.add(666);
	L3.add(777);

	L1.print();
	L2.print();
	L3.print();

	Node<int>* L1L2Intersection = intersects(L1, L2);
	Node<int>* L2L3Intersection = intersects(L2, L3);
	if (L1L2Intersection) {
		cout << "L1 intersects with L2 at " << L1L2Intersection->getItem() << endl;
	}
	else {
		cout << "L1 doesn't intersect with L2" << endl;
	}

	if (L2L3Intersection) {
		cout << "L2 intersects with L3 at " << L2L3Intersection->getItem() << endl;
	}
	else {
		cout << "L2 doesn't intersect with L3" << endl;
	}
	return 0;
}
