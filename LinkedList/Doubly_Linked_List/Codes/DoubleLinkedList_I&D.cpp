// Doubly Linked Lists
// Insertions, Deletions, And basic data structure operations (Traverse & Count)
// Much, Much tougher and practice demanding than SLL
// No Mistake Code : 27/07/25

// - ASWalia

#include<iostream>
using namespace std;

// Defining Node As An ADT (Abstract Data Type) For Doubly Linked List
struct Node {
	Node* prev;
	int value;
	Node* next;
};

// Function To Print The Doubly Linked List
void print_list(Node* n) {
	while (n != nullptr) {
		cout << n->value << " ";
		n = n->next;
	}
}

// Function To Count The Number Of Nodes In The List
int count_list(Node* Head) {
	int count = 0;
	while (Head != nullptr) {
		count++;
		Head = Head->next;
	}
	return count;
}

// Function To Insert A Node At The Beginning Of The List
void InsertAtBeginning(Node*& Head, int newval) {
	Node* newnode = new Node();
	newnode->prev = nullptr;
	newnode->value = newval;
	newnode->next = nullptr;

	if (Head != nullptr) {
		newnode->next = Head;
		Head->prev = newnode;
	}
	Head = newnode;
}

// Function To Insert A Node At The End Of The List
void InsertAtEnd(Node*& Head, int newval) {
	Node* newnode = new Node();
	newnode->prev = nullptr;
	newnode->value = newval;
	newnode->next = nullptr;

	if (Head == nullptr) {
		Head = newnode;
		return;
	}

	Node* last = Head;
	while (last->next != nullptr) {
		last = last->next;
	}
	newnode->prev = last;
	last->next = newnode;
}

// Function To Insert A Node After A Given Node
void InsertAfter(Node* prev, int newval) {
	Node* newnode = new Node();
	newnode->prev = nullptr;
	newnode->value = newval;
	newnode->next = nullptr;

	if (prev == nullptr) {
		cout << "ERROR. Can't Insert After Nullptr" << endl;
		return;
	}

	newnode->next = prev->next;
	newnode->prev = prev;

	if (prev->next != nullptr) {
		prev->next->prev = newnode;
	}
	prev->next = newnode;
}

// Function To Delete The First Node Of The List
void DeleteFirst(Node*& Head) {
	if (Head == nullptr) {
		cout << "ERROR. Can't Delete From Empty List" << endl;
		return;
	}
	Node* temp = Head;
	Head = Head->next;
	temp->next = nullptr;
	delete(temp);
}

// Function To Delete The Last Node Of The List
void DeleteLast(Node*& Head) {
	if (Head == nullptr) {
		cout << "ERROR. Can't Delete From Empty List" << endl;
		return;
	}

	if (Head->next == nullptr) {
		DeleteFirst(Head);
		return;
	}

	Node* prev = nullptr;
	Node* curr = Head;

	while (curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;
	curr->prev = nullptr;
	delete(curr);
}

// Function To Delete A Node At A Given Position (1-Based Index)
void DeleteThisNode(int pos, Node*& Head) {
	if (Head == nullptr) {
		cout << "ERROR. Can't Delete From Empty List" << endl;
		return;
	}

	if (pos == 1) {
		DeleteFirst(Head);
		return;
	}

	int len = count_list(Head);

	if (pos > len || pos <= 0) {
		cout << "ERROR. Enter Position Within Range Of The DLL" << endl;
		return;
	}

	Node* prev = nullptr;
	Node* curr = Head;

	for (int i = 1; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;
	if (curr->next != nullptr) {
		curr->next->prev = prev;
	}
	delete(curr); // Free The Memory Of The Deleted Node
}

// Function To Delete All Nodes In The List
// Head no longer points to dangling pointer
void delete_all(Node*& Head) {
	while (Head != nullptr) {
		DeleteFirst(Head);
	}
	Head = nullptr;
}

int main() {

	// Creating Initial List With Three Nodes
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->prev = nullptr;
	head->value = 1;
	head->next = second;

	second->prev = head;
	second->value = 2;
	second->next = third;

	third->prev = second;
	third->value = 3;
	third->next = nullptr;

	cout << "Original List -->" << endl;
	print_list(head);
	cout << "\nNumber Of Elements In List: " << count_list(head) << endl;

	cout << "\nAfter Inserting -->" << endl;
	InsertAtBeginning(head, 0);
	InsertAtEnd(head, 100);
	InsertAfter(third, 4);
	print_list(head);
	cout << "\nNumber Of Elements In List: " << count_list(head) << "\n" << endl;

	cout << "After Deleting -->" << endl;
	DeleteFirst(head);
	DeleteLast(head);
	DeleteThisNode(4, head);
	print_list(head);
	cout << "\nNumber Of Elements In List: " << count_list(head) << endl;

	// Deleting All Nodes In The List
	cout << "\nDeleting All Nodes -->" << endl;
	delete_all(head);

	// Can't Traverse A Null List So Skip Further Output
	// print_list(head);
	// cout << "\nNumber Of Elements In List: " << count_list(head) << endl;

	return 0;
}
