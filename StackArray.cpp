#include "StackArray.h"

template< typename DataType >
StackArray<DataType>::StackArray(int maxNumber)
	: Stack<DataType>::Stack() {
	maxSize = maxNumber;
	top = -1;
	dataItems = new DataType[maxSize];
}

template < typename DataType >
StackArray<DataType>::StackArray(const StackArray& other)
	: Stack<DataType>::Stack() {
	*this = other;
}

template < typename DataType >
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other) {
	maxSize = other.maxSize;
	top = other.top;
	dataItems = new DataType[maxSize];
	for (int i = 0; i <= top; i++) {
		dataItems[i] = other.dataItems[i];
	}
	return *this;
}

template < typename DataType >
StackArray<DataType>::~StackArray() {
	delete dataItems;
}

template < typename DataType >
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error) {
	if (isFull()) {
		throw logic_error("e");
	}
	else {
		dataItems[++top] = newDataItem;
	}
}

template < typename DataType >
DataType StackArray<DataType>::pop() throw (logic_error) {
	if (isEmpty()) {
		throw logic_error("e");
	}
	else {
		return dataItems[top--];
	}
}

template < typename DataType >
void StackArray<DataType>::clear() {
	delete dataItems;
	dataItems = new DataType[maxSize];
	top = -1;
}

template < typename DataType >
bool StackArray<DataType>::isEmpty() const {
	return top == -1;
}

template < typename DataType >
bool StackArray<DataType>::isFull() const {
	return top == maxSize - 1;
}