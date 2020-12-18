#include "LinkedList.h"
#include "iostream"
using namespace std;

template<class ItemType>
LinkedList<ItemType>::LinkedList(): head(nullptr), itemCount(0)
{
}

template<class ItemType>
int LinkedList<ItemType>::size() const {
    return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::empty() const {
    return itemCount == 0;
}

template<class ItemType>
void LinkedList<ItemType>::add(const ItemType& newItem) {
    Node<ItemType>* newItemNode = new Node<ItemType>(newItem, head);
    head = newItemNode;
    itemCount++;
}

template<class ItemType>
void LinkedList<ItemType>::addToTail(const ItemType& newItem)
{
    Node<ItemType>* newNode = new Node<ItemType>(newItem);
    if (head == NULL)
    {
        head = newNode;
        itemCount++;
        return;
    }
    Node<ItemType>* currNode = head;
    while (currNode->getNext() != NULL) {
        currNode = currNode->getNext();
    }
    currNode->setNext(newNode);
    itemCount++;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(const ItemType& item) {
    auto* prevNode = new Node<ItemType>;
    auto* currentNode = new Node<ItemType>;
    if (head) {
        if (head->getItem() == item) {
            head = head->getNext();
            itemCount--;
            return true;
        }
        prevNode = head;
        currentNode = head->getNext();
    }
    while (currentNode != nullptr) {
        if (currentNode->getItem() == item) {
            prevNode->setNext(currentNode->getNext());
            itemCount--;
            return true;
        }
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }
    return false;
}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    if (head) {
        auto* currentNode = head;
        auto* nextNode = new Node<ItemType>;
        while (currentNode != nullptr) {
            nextNode = currentNode->getNext();
            delete currentNode;
            currentNode = nextNode;
        }
        head = nullptr;
        itemCount = 0;
    }
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::contains(const ItemType& item) const {
    auto* prevNode = new Node<ItemType>;
    auto* currentNode = new Node<ItemType>;
    if (head) {
        if (head->getItem() == item) {
            return head;
        }
        prevNode = head;
        currentNode = head->getNext();
    }
    while (currentNode != nullptr) {
        if (currentNode->getItem() == item) {
            return currentNode;
        }
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }
    return NULL;
}

template<class ItemType>
int LinkedList<ItemType>::getFrequencyOf(const ItemType& item) const {
    int count = 0;
    auto* prevNode = new Node<ItemType>;
    auto* currentNode = new Node<ItemType>;
    if (head) {
        if (head->getItem() == item) {
            count++;
        }
        prevNode = head;
        currentNode = head->getNext();
    }
    while (currentNode != nullptr) {
        if (currentNode->getItem() == item) {
            count++;
        }
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }
    return count;
}

template<class ItemType>
void LinkedList<ItemType>::print() const {
    cout << "Linked list content: ";
    auto* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->getItem() << " -> ";
        currentNode = currentNode->getNext();
    }
    cout << "#" << endl;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getHead() const {
    return head;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(void)
{
}
