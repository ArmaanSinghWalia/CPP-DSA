// Singly Linked List
// Full Implementation: Insertions, Deletions, Traversal, Count
// Extended version with InsertAtPos, DeleteAfter, DeleteByValue

// Wrote My First, Zero-Mistakes Code On 09/07/2025
// Refined for clarity on 07/09/2025

// - ASWalia

#include<iostream>
using namespace std;

// Structure Of Node
class Node {
public:
	int value;
	Node* next;
};

// Displaying Linked List (Traverse + Print)
void display(Node* Head) {
	while (Head != nullptr) {
		cout << Head->value << " ";
		Head = Head->next;
	}
}

// Counting Number Of Nodes In The List
int Count(Node* Head) {
	int count = 0;
	while (Head != nullptr) {
		count++;
		Head = Head->next;
	}
	return count;
}

// Inserting Node At The Beginning
void InsertAtBeginning(Node*& Head, int newval) {

	// Make New Node
	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = Head;

	// Update Head
	Head = newnode;
}

// Inserting Node At The End
void InsertAtEnd(Node*& Head, int newval) {

	// Make New Node
	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = nullptr;

	// If List Is Empty
	if (Head == nullptr) {
		Head = newnode;
		return;
	}

	// Traverse To Last Node
	Node* last = Head;
	while (last->next != nullptr) {
		last = last->next;
	}

	last->next = newnode;
}

// Inserting Node After A Specific Node
void InsertAfter(Node* prev, int newval) {

	// Check Null Case
	if (prev == nullptr) {
		cout << "Error: Cannot insert after nullptr.\n";
		return;
	}

	// Make New Node
	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = prev->next;
	prev->next = newnode;
}

// Inserting Node At A Given Position (1-based)
void InsertAtPos(int pos, int newval, Node*& Head) {

	int size = Count(Head);

	// Out of Range Check
	if (pos > size + 1 || pos <= 0) {
		cout << "Error: Enter position within range of the list.\n";
		return;
	}

	// Insert At Beginning
	if (pos == 1 || Head == nullptr) {
		InsertAtBeginning(Head, newval);
		return;
	}

	// Insert At End
	if (pos == size + 1) {
		InsertAtEnd(Head, newval);
		return;
	}

	// Insert At Middle
	Node* newnode = new Node();
	newnode->value = newval;

	Node* prev = Head;
	for (int i = 1; i < pos - 1; i++) {
		prev = prev->next;
	}

	newnode->next = prev->next;
	prev->next = newnode;
}

// Deleting First Node
void DeleteFirst(Node*& Head) {

	if (Head == nullptr) {
		cout << "Error: List is already empty.\n";
		return;
	}

	Node* temp = Head;
	Head = Head->next;
	delete temp;
}

// Deleting Last Node
void DeleteLast(Node*& Head) {

	// Case: Empty List
	if (Head == nullptr) {
		cout << "Error: List is already empty.\n";
		return;
	}

	// Case: Only One Node
	if (Head->next == nullptr) {
		delete Head;
		Head = nullptr;
		return;
	}

	// Traverse To Second Last
	Node* prev = nullptr;
	Node* curr = Head;

	while (curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = nullptr;
	delete curr;
}

// Deleting Node At A Given Position
void DeleteAtPos(int pos, Node*& Head) {

	int size = Count(Head);

	// Case: Empty List
	if (Head == nullptr) {
		cout << "Error: List is already empty.\n";
		return;
	}

	// Out of Range
	if (pos > size || pos <= 0) {
		cout << "Error: Enter valid position.\n";
		return;
	}

	// Case: First Node
	if (pos == 1) {
		DeleteFirst(Head);
		return;
	}

	// Traverse To The Node
	Node* prev = nullptr;
	Node* curr = Head;

	for (int i = 1; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;
	delete curr;
}

// Deleting Node After A Specific Node
void DeleteAfter(Node* Prev) {

	// Null Check
	if (Prev == nullptr) {
		cout << "Error: Cannot delete after nullptr.\n";
		return;
	}

	Node* Temp = Prev->next;

	// If No Node After Prev
	if (Temp == nullptr) {
		cout << "Error: No node exists after given node.\n";
		return;
	}

	Prev->next = Temp->next;
	delete Temp;
}

// Deleting Node By Value
void DeleteByValue(int val, Node*& Head) {

	// Case: Empty List
	if (Head == nullptr) {
		cout << "Error: List is already empty.\n";
		return;
	}

	// Case 1: Head Node Matches
	if (Head->value == val) {
		Node* temp = Head;
		Head = Head->next;
		delete temp;
		return;
	}

	// Case 2: Search Further
	Node* curr = Head;
	while (curr->next && curr->next->value != val) {
		curr = curr->next;
	}

	// Not Found
	if (curr->next == nullptr) {
		cout << "Error: Node with value " << val << " not found.\n";
		return;
	}

	// Delete Matching Node
	Node* temp = curr->next;
	curr->next = temp->next;
	delete temp;
}

// Main Function
int main() {

	// Making 3 Nodes
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->value = 1;
	head->next = second;

	second->value = 2;
	second->next = third;

	third->value = 3;
	third->next = nullptr;

	// Initial List
	cout << "Original List -->" << endl;
	display(head);
	cout << "\nNumber of elements: " << Count(head) << endl;

	// Insertions
	InsertAtBeginning(head, 0);     // 0 1 2 3
	InsertAtEnd(head, 100);        // 0 1 2 3 100
	InsertAfter(third, 22);        // 0 1 2 3 22 100
	InsertAtPos(3, 1000, head);    // 0 1 1000 2 3 22 100  

	cout << "\nAfter Insertions -->" << endl;
	display(head);
	cout << "\nNumber of elements: " << Count(head) << endl;

	// Deletions
	DeleteFirst(head);             // 1 1000 2 3 22 100
	DeleteLast(head);              // 1 1000 2 3 22
	DeleteAtPos(5, head);          // 1 1000 2 3
	DeleteAfter(head);             // 1 2 3
	DeleteByValue(2, head);        // 1 3

	cout << "\nAfter Deletions -->" << endl;
	display(head);
	cout << "\nNumber of elements: " << Count(head) << endl;

	return 0;
}

