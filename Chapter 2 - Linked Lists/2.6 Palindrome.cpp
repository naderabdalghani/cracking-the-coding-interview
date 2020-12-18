#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;


bool isPalindromeRecurHelper(Node<int>*& left, Node<int>* right) {
	if (right == NULL) {
		return true;
	}
	bool check = isPalindromeRecurHelper(left, right->getNext());
	if (!check)
	{
		return false;
	}
	check = left->getItem() == right->getItem();
	left = left->getNext();
	return check;
}

bool isPalindrome(Node<int>* head) {
	return isPalindromeRecurHelper(head, head);
}


int main() {
	LinkedList<int> L1, L2, L3;
	L1.add(1);
	L1.add(1);
	L1.add(2);
	L1.add(1);

	L2.add(1);
	L2.add(2);
	L2.add(3);
	L2.add(5);
	L2.add(3);
	L2.add(2);
	L2.add(1);

	L3.add(2);
	L3.add(3);
	L3.add(4);
	L3.add(5);
	L3.add(6);
	L3.add(7);
	L3.add(8);

	L1.print();
	cout << "is the previous list a palindrome? " << (isPalindrome(L1.getHead()) ? "yes" : "no") << endl;

	L2.print();
	cout << "is the previous list a palindrome? " << (isPalindrome(L2.getHead()) ? "yes" : "no") << endl;

	L3.print();
	cout << "is the previous list a palindrome? " << (isPalindrome(L3.getHead()) ? "yes" : "no") << endl;
	return 0;
}
