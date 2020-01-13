#include "StackLinked.h"

template < typename DataType >
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr) {
	dataItem = nodeData;
	next = nextPtr;
}

template < typename DataType >
StackLinked<DataType>::StackLinked(int maxNumber)
	: Stack<DataType>::Stack() {
	maxSize = maxNumber;
	numNodes = 0;
	top = nullptr;
}

template < typename DataType >
StackLinked<DataType>::StackLinked(const StackLinked& other)
	: Stack<DataType>::Stack() { 
	maxSize = other.maxSize;
	numNodes = 0;
	top = nullptr;
	*this = other;
}

template < typename DataType >
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other) {
	clear();
	if (!other.isEmpty()) {
		copyHelper(other.top);
	}
	return *this;
}

template < typename DataType >
StackLinked<DataType>::~StackLinked() {
	clear();
}

template < typename DataType >
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error) {
	if (isFull()) {
		throw logic_error("e");
	}
	else if (isEmpty()) {
		StackNode* node = new StackNode(newDataItem, nullptr);
		top = node;
	}
	else {
		StackNode* node = new StackNode(newDataItem, top);
		top = node;
	}
	numNodes++;
}

template < typename DataType >
DataType StackLinked<DataType>::pop() throw (logic_error) {
	if (isEmpty()) {
		throw logic_error("e");
	}
	else {
		DataType item = top->dataItem;
		StackNode* temp = top;
		top = top->next;
		delete temp;
		temp = nullptr;
		numNodes--;
		return item;
	}
}

template < typename DataType >
void StackLinked<DataType>::clear() {
	while (!isEmpty()) {
		pop();
	}
}

template < typename DataType >
bool StackLinked<DataType>::isEmpty() const {
	return top == nullptr;
}

template < typename DataType >
bool StackLinked<DataType>::isFull() const {
	return numNodes == maxSize;
}

template < typename DataType >
void StackLinked<DataType>::copyHelper(StackNode* current) {
	if (current->next != nullptr) {
		copyHelper(current->next);
	}
	push(current->dataItem);
}