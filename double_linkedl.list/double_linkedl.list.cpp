#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string  name;
	Node* name;
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