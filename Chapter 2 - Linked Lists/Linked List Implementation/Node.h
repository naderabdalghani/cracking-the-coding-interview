#pragma once

template<class ItemType>
class Node {
private:
	Node<ItemType>* next;
	ItemType data;
public:
	Node();
	explicit Node(const ItemType&);
	Node(const ItemType&, Node<ItemType>*);
	void setItem(const ItemType&);
	void setNext(Node<ItemType>*);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};

