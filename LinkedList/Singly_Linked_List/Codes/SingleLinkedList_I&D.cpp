// Singly Linked Lists
// Insertions, Deletions, And basic data structure operations (Traverse & Count)
// Wrote My First, Zero-Mistakes Code On 09/07/2025

// - ASWalia

#include<iostream>
using namespace std;

// Structure Of Node
class Node {
public:

	int value;
	Node* next;
};

// Displaying Linked List (value)
void print_list(Node* Head) {

	while (Head != nullptr) {
		cout << Head->value << " ";
		Head = Head->next;
	}
}

// Counting Number Of Nodes Of The Linked List
int count_list(Node* Head) {
	int count = 0;

	while (Head != nullptr) {
		count++;
		Head = Head->next;
	}
	return count;
}

// Inserting Node At The Beginning Of The Linked List
void InsertAtBeginning(Node*& Head, int newval) {

	// Making New Node
	Node* newnode = new Node();                                           
	newnode->value = newval;
	newnode->next = Head;

	// Updating Head
	Head = newnode;  
}

// Inserting Node At The End Of The Linked List
void InsertAtEnd(Node*& Head, int newval) {

	// Making New Node
	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = nullptr;

	// If List Is Empty
	if (Head == nullptr) {
		// head ptr points to newnode . . . list has one node
		Head = newnode;
		return;
	}

	Node* last = Head;

	// Traversing To End Node
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newnode;
}

// Inserting Node After A Specific Node Of The Linked List
void InsertAfter(Node* prev, int newval) {
	
	// check !prev
	if (prev == nullptr) {
		cout << "Error: List is empty.\n";
		return;
	}

	// Make Newnode
	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = prev->next;
	prev->next = newnode;
}

// Deleting First Node Of The Linked List
void DeleteFirst(Node*& Head) {

	// check !Head
	if (Head == nullptr) {
		cout << "Error: List is empty.\n";
		return;
	}

	Node* temp = Head;

	if (Head->next != nullptr) {
		Head = Head->next;
	}	
	delete(temp);
}

void DeleteLast(Node*& Head) {

	// Check !Head
	if (Head == nullptr) {
		cout << "Error: List is empty.\n";
		return;
	}

	// Check For One Node
	if (Head->next == nullptr) {
		DeleteFirst(Head);
		return;
	}

	// New Nodes For Deletion 
	Node* prev = nullptr;
	Node* curr = Head;

	while (curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next; // nullptr
	delete(curr);
}

void DeleteThisNode(int pos, Node*& Head) {

	// Check If List Is Empty
	if (Head == nullptr) {
		cout << "Error: List is empty.\n";
		return;
	}

	int list_len = count_list(Head);

	// Check If Position Not In Range
	if (pos > list_len or pos <= 0) {
		cout << "Error: Invalid position.\n";
		return;
	}

	// Check If Pos == 1 . . . Deleting First Node
	if (pos == 1) {
		DeleteFirst(Head);
		return;
	}

	Node* prev = nullptr;
	Node* curr = Head;

	for (int i = 1; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}
	// curr points to the Node to be deleted

	prev->next = curr->next;
	delete(curr);
}


int main() {

	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->value = 1;
	head->next = second;
	second->value = 2;
	second->next = third;
	third->value = 3;
	third->next = nullptr;

	cout << "original list -->\n" << endl;
	print_list(head);
	cout << "\nnumber of elements: " << count_list(head) << endl;

	InsertAtBeginning(head, 0);
	InsertAtEnd(head, 100);
	InsertAfter(third, 4);

	cout << "\n\nAfter Insertions -->" << endl;
	print_list(head);
	cout << "\nnumber of elements: " << count_list(head) << endl;

	DeleteFirst(head);
	DeleteLast(head);
	DeleteThisNode(4, head);

	cout << "\n\nAfter Deletions -->" << endl;
	print_list(head);
	cout << "\nnumber of elements: " << count_list(head) << endl;


	return 0;
}