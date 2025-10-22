// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// index from zero, so if deleting 3rd element
// middle element is gint of the size

#include<iostream>
using namespace std;

class Node {
public:

	int value;
	Node* next;
};

void Display(Node* n) {
	while (n) {
		cout << n->value << " ";
		n = n->next;
	}
}

int count(Node* n){
	int size = 0;
	while (n) {
		size++;
		n = n->next;
	}
	return size;
}

//returns middle node
Node* OneBeforeMiddle(Node* Head) {

	// number of nodes in the linked list
	int size = count(Head);

	// middle element is greatest integer function applied on size / 2
	// so fractional part is discarded by explicit type conversion
	int mid = size / 2;
	Node* prev = nullptr;
	
	// shifitng the head pointer to point to middle element
	// note here inclusive unlike in middle_of_SLL problem as here we're doing implicit type conversion instead of defining the middle node position
	for (int i = 1; i <= mid; i++) {
		prev = Head;
		Head = Head->next;
	}
	// return node previous to middle node
	return prev;
}

Node* DeleteMiddleElement(Node* Head) {

	// empty list
	if (!Head) return nullptr;

	// one node
	if (!Head->next) {
		Node* temp = Head;
		Head = Head->next;
		delete temp;
		return nullptr;
	}

	// get pointer to node before middle element
	Node* prevMidNode = OneBeforeMiddle(Head);

	// deleting by node
	Node* MidNode = prevMidNode->next;

	prevMidNode->next = MidNode->next;
	delete MidNode;

	return Head;
}

void InsertAtEnd(Node*& Head, int newval) {

	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = nullptr;

	if (!Head) {
		Head = newnode;
		return;
	}

	Node* last = Head;
	while (last->next) {
		last = last->next;
	}
	last->next = newnode;
}

int main() {

	Node* head = nullptr;

	InsertAtEnd(head, 1);
	InsertAtEnd(head, 2);
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 4);
	InsertAtEnd(head, 5);

	cout << "Original list -->" << endl;
	Display(head);

	cout << "\nDeleting middle element and displaying -->" << endl;
	Node* newHead = DeleteMiddleElement(head);
	Display(newHead);


	return 0;
}