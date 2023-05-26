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
	void hapus();
	void searchData();
};

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