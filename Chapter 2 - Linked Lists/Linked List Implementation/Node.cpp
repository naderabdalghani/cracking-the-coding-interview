#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {}

template<class ItemType>
Node<ItemType>::Node(const ItemType& item) : data(item), next(nullptr) {}

template<class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType>* nextNode) : data(item), next(nextNode) {}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& item) {
    data = item;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNode) {
    next = nextNode;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return data;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}
