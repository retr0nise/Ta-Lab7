#pragma once
#include <iostream>
#include "LinkedListNode.h"
#include "toString.h"

template<typename T>
class LinkedList
{
private:
	int _count = 0;
	LinkedListNode<T>* _first = nullptr;
	LinkedListNode<T>* _last = nullptr;
public:
	int getCount() const {
		return _count;
	}
	int getNumberByCondition(std::function<bool(int)> condition) const {
		int number = 0;
		LinkedListNode<T>* next = _first;
		while (next != nullptr) {
			if (condition(next->Value)) {
				number++;
			}
			next = next->NextNode;
		}
		return number;
	}

	LinkedListNode<T>* getFirst() const {
		return _first;
	}
	LinkedListNode<T>* getLast() const {
		return _last;
	}
	void addLast(LinkedListNode<T>* node) {
		if (_last == nullptr) {
			_first = node;
			_last = node;
		}
		else {
			LinkedListNode<T>* prev = _last;
			_last->NextNode = node;
			_last = node;
			_last->PreviousNode = prev;
		}
		_count++;
	}
	void addFirst(LinkedListNode<T>* node) {
		if (_first == nullptr) {
			_first = node;
			_last = node;
		}
		else {
			LinkedListNode<T>* next = _first;
			_first = node;
			next->PreviousNode = _first;
			_first->NextNode = next;



		}
		_count++;
	}
	void changeFirstToLast() {
		if (_first == nullptr) {
			system("cls");
			std::cout << "Don`t have any numbers\n";
			system("pause");
			return;
		}
		if (_first == _last) {
			system("cls");
			std::cout << "Only one number\n";
			system("pause");
			return;
		}
		LinkedListNode<T>* fst = _first;
		LinkedListNode<T>* las = _last;
		if (_count == 2) {

			_last = _first;
			_last->NextNode = nullptr;


			_first = las;
			_first->PreviousNode = nullptr;
			_last->PreviousNode = _first;
			_first->NextNode = _last;
			return;
		}

		_first = las;
		_first->NextNode = fst->NextNode;
		_last = fst;
		_last->PreviousNode = las->PreviousNode;
		_first->NextNode->PreviousNode = _first;


		_last->PreviousNode->NextNode = _last;
		_last->NextNode = nullptr;
		_first->PreviousNode = nullptr;
	}

	LinkedListNode<T>* removeLast() {
		if (_count == 0) {
			system("cls");
			std::cout << "Don`t have any numbers\n";
			system("pause");
			return 0;
		}
		LinkedListNode<T>* removedNode = _last;
		if (_count == 1) {
			_first = nullptr;
			_last = nullptr;
			_count--;
			return removedNode;
		}

		_last->PreviousNode->NextNode = nullptr;
		_last = _last->PreviousNode;


		_count--;
		return removedNode;

	}
	LinkedListNode<T>* removeFirst() {
		if (_count == 0) {
			system("cls");
			std::cout << "Don`t have any numbers\n";
			system("pause");
			return 0;
		}
		LinkedListNode<T>* removedNode = _first;
		if (_count == 1) {
			_first = nullptr;
			_last = nullptr;
			_count--;
			return removedNode;
		}

		_first->NextNode->PreviousNode = nullptr;
		_first = _first->NextNode;


		_count--;
		return removedNode;

	}

	friend std::ostream& operator <<(std::ostream& os, const LinkedList<T>& list) {
		if (list.getCount() == 0) {
			return os;
		}

		auto next = list.getFirst();
		os << *next;
		while (next->NextNode != nullptr) {
			next = next->NextNode;
			os << " - " << *next;
		}
		return os;
	}
};