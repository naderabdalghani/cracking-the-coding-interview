#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

LinkedList<int> sumLists(LinkedList<int> const &L1, LinkedList<int> const &L2) {
	LinkedList<int> result;
	Node<int>* currNode1 = L1.getHead();
	Node<int>* currNode2 = L2.getHead();
	int carry = 0;
	while (currNode1 != NULL || currNode2 != NULL)
	{
		int item1 = currNode1 != NULL ? currNode1->getItem() : 0;
		int item2 = currNode2 != NULL ? currNode2->getItem() : 0;
		int sum = item1 + item2 + carry;
		int remainder = sum % 10;
		carry = sum / 10;
		result.addToTail(remainder);
		currNode1 = currNode1 != NULL ? currNode1->getNext() : NULL;
		currNode2 = currNode2 != NULL ? currNode2->getNext() : NULL;
	}
	if (carry)
	{
		result.addToTail(carry);
	}
	return result;
}

LinkedList<int> sumListsReversed(Node<int>* const& node1, Node<int>* const& node2, int &carry) {
	LinkedList<int> result;
	if (node1 == NULL)
	{
		Node<int>* resultHead = result.getHead();
		resultHead = node2;
		return result;
	}
	if (node2 == NULL)
	{
		Node<int>* resultHead = result.getHead();
		resultHead = node1;
		return result;
	}
	if (node1->getNext() != NULL || node2->getNext() != NULL)
	{
		Node<int>* next1 = node1->getNext() != NULL ? node1->getNext() : node1;
		Node<int>* next2 = node2->getNext() != NULL ? node2->getNext() : node2;
		result = sumListsReversed(next1, next2, carry);
	}
	int sum = node1->getItem() + node2->getItem() + carry;
	int remainder = sum % 10;
	carry = sum / 10;
	result.add(remainder);
	return result;
}

void pad(LinkedList<int>& L1, LinkedList<int>& L2) {
	if (L1.size() > L2.size())
	{
		int sizeIncrease = L1.size() - L2.size();
		for (int i = 0; i < sizeIncrease; i++)
		{
			L2.add(0);
		}
		return;
	}
	int sizeIncrease = L2.size() - L1.size();
	for (int i = 0; i < sizeIncrease; i++)
	{
		L1.add(0);
	}
}

int main() {
	LinkedList<int> L1, L2;
	L1.add(1);
	L1.add(7);

	L2.add(2);
	L2.add(5);
	L2.add(9);
	L2.add(5);

	cout << "Adding:" << endl;
	L1.print();
	L2.print();

	cout << "Result:" << endl;
	int carry = 0;
	pad(L1, L2);
	LinkedList<int> result = sumListsReversed(L1.getHead(), L2.getHead(), carry);
	result.print();
	return 0;
}
