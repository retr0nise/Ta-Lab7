// Lb6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include "LinkedListNode.h"
#include "LinkedList.h"

using namespace std;

void viewAddLastScreen(LinkedList<int>& list) {
	system("cls");
	cout << "Input value: ";
	int value = 0;
	cin >> value;
	list.addLast(new LinkedListNode<int>(value));
}
void viewAddFirstScreen(LinkedList<int>& list) {
	system("cls");
	cout << "Input value: ";
	int value = 0;
	cin >> value;

	list.addFirst(new LinkedListNode<int>(value));
}

void handleInvalidInput() {
	cout << "You inputed the invalid command! Try again!\n";
	system("pause");
}


void startList() 
{
	system("color 0F");
	LinkedList<int> list;

	bool isContinue = true;
	while (isContinue) {
		system("cls");
		cout << "1. Add last" << endl;
		cout << "2. Add first" << endl;
		cout << "3. Remove the last" << endl;
		cout << "4. Remove first" << endl;
		cout << "5. Change first and last" << endl;
		cout << "6. Exit" << endl;
		cout << "Your list: " << list << endl;
		cout << "Element cout: " << list.getCount() << endl;
		cout << "\nInput command: ";
		char command = 0;
		cin >> command;
		switch (command) {
		case '1': viewAddLastScreen(list);						break;
		case '2': viewAddFirstScreen(list);						break;
		case '3': delete list.removeLast();						break;
		case '4': delete list.removeFirst();					break;
		case '5': list.changeFirstToLast();						break;
		case '6': isContinue = false;							break;
		default: handleInvalidInput();							break;
		}
	}
	return;
}
void startQueue()
{
	system("color 09");
	LinkedList<int> list;

	bool isContinue = true;
	while (isContinue) {
		system("cls");
		cout << "1. Add In Queue (push)" << endl;
		cout << "2. Remove from Queue (pup)" << endl;
		cout << "3. Exit" << endl;
		cout << "Your Queue: " << list << endl;
		cout << "Element cout: " << list.getCount() << endl;
		cout << "\nInput command: ";
		char command = 0;
		cin >> command;
		switch (command) {
		case '1': viewAddLastScreen(list);						break;
		case '2': delete list.removeFirst();					break;
		case '3': isContinue = false;							break;
		default: handleInvalidInput();							break;
		}
	}
	return;
}
void startStack()
{
	system("color 0E");
	LinkedList<int> list;

	bool isContinue = true;
	while (isContinue) {
		system("cls");
		cout << "1. Add to Stack (push)" << endl;
		cout << "2. Remove from Stack (pup)" << endl;
		cout << "3. Exit" << endl;
		cout << "Your Srack: " << list << endl;
		cout << "Element cout: " << list.getCount() << endl;
		cout << "\nInput command: ";
		char command = 0;
		cin >> command;
		switch (command) {
		case '1': viewAddLastScreen(list);						break;
		case '2': delete list.removeLast();						break;
		case '3': isContinue = false;							break;
		default: handleInvalidInput();							break;
		}
	}
	return;
}
void startDeq()
{
	system("color 06");
	LinkedList<int> list;

	bool isContinue = true;
	while (isContinue) {
		system("cls");
		cout << "1. Add to End" << endl;
		cout << "2. Add to Beginning" << endl;
		cout << "3. Remove from End" << endl;
		cout << "4. Remove from Beginning" << endl;
		cout << "5. Exit" << endl;
		cout << "Your Deq: " << list << endl;
		cout << "Element cout: " << list.getCount() << endl;
		cout << "\nInput command: ";
		char command = 0;
		cin >> command;
		switch (command) {
		case '1': viewAddLastScreen(list);						break;
		case '2': viewAddFirstScreen(list);						break;
		case '3': delete list.removeLast();						break;
		case '4': delete list.removeFirst();					break;
		case '5': isContinue = false;							break;
		default: handleInvalidInput();							break;
		}
	}
	return;
}

int main()
{
	bool isContinue = true;
	while (isContinue) 
	{
		system("color 0F");
		system("cls");
		cout << "1. Start Stack" << endl;
		cout << "2. Start Queue " << endl;
		cout << "3. Start Deq" << endl;
		cout << "4. Start Full" << endl;
		cout << "5. Exit" << endl;
		char command = 0;
		cin >> command;
		switch (command)
		{
		case '1': startStack();									break;
		case '2': startQueue();									break;
		case '3': startDeq();									break;
		case '4': startList();									break;
		case '5': isContinue = false;							break;
		default : handleInvalidInput();		    				break;
		}
	}
	return 0;
}