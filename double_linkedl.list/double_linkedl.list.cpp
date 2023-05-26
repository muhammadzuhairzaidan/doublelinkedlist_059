#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string  name;
	Node* next;
	Node* prev;

};

class DoubleLinkedList {
private:
	Node* START = NULL;
public:
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();

};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\mEnter the roll nummber of the student: ";
	cin >> nim;
	cout << " \nEnter name of the student: ";
	cin >> nm;

	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; //step 2
	newNode->name = nm; //step 2

	/*insert a node  in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) { //Check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //Step 3
		if (START != NULL)
			START->prev = newNode; //Step 4
		newNode->prev = NULL; //Step 5
		START = newNode; //Step 6
		return;
	}

	/*Inserting a Node Between two Nodes in the List*/
	Node* current = START; //1.a
	Node* previous = NULL; //1.b
	while (current->next != NULL && current->next->noMhs < nim) //Step 1.c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next; //Step 4
	newNode->prev = current; //Step 5
	if (current->next != NULL)
		current->next->prev = newNode; //Step 6
	current->next = newNode; //Step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL; //Step 1.a
	*current = START; //Step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) { //Step 1.c
		*previous = *current; //Step 1.d
		*current = (*current)->next; //Step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; //Step 2
	if (previous != NULL)
		previous->next = current->next; //Step 3
	else
		START = current->next;

	delete current; //Step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is Empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
 		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is Empty" << endl;
	}

	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}
void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is Empty" << endl;
	}

	cout << "\nEnter the roll number of the student whose record is to be deleted:";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << " deleted " << endl;
}

	