#pragma once
#include <iostream>

template<typename T>
class LinkedListNode
{
public:
	T Value;
	LinkedListNode<T>* NextNode;
	LinkedListNode<T>* PreviousNode;

	LinkedListNode(T value, LinkedListNode<T>* next = nullptr, LinkedListNode<T>* previous = nullptr)
		: Value(value), NextNode(next), PreviousNode(previous) {}

	friend std::ostream& operator <<(std::ostream& os, const LinkedListNode<T>& node) {

		return os << '[' << node.Value << ']';
	}
};

