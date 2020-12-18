#pragma once
#include "Node.h"
#include "Node.cpp"

template<class ItemType>
class LinkedList {
private:
    Node<ItemType>* head;
    int itemCount;
public:
    LinkedList();
    int size() const;
    bool empty() const;
    void add(const ItemType& newItem);
    void addToTail(const ItemType& newItem);
    bool remove(const ItemType& item);
    void clear();
    Node<ItemType>* contains(const ItemType& item) const;
    int getFrequencyOf(const ItemType& item) const;
    void print() const;
    Node<ItemType>* getHead() const;
    ~LinkedList(void);
};
