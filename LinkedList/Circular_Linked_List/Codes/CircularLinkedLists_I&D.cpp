#include<iostream>
using namespace std;

class Node {
public:

	int value;
	Node* next;
};

void PrintList(Node* Head) {
	if (Head == nullptr) {
		cout << "oops. left is empty" << endl;
		return;
	}
	Node* temp = Head;           // you need to save the Head ptr as circular linked list
	do {
		cout << temp->value << " ";
		temp = temp->next;
	} while (temp != Head);
}

int CountList(Node* Head) {
	 
	int count = 0;               // Now dont have to write return 0 explicitly. Returns initial value of count (0)       

	if (Head == nullptr) {
		cout << "list is empty. zero elements !!" << endl;
		return count; 
	}
	Node* temp = Head;
	do {
		count++;
		temp = temp->next;
	} while (temp != Head);
	return count;
}

void InsertInBeginning(Node*& Head, int newval) {
	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = nullptr;

	// Empty list check
	if (Head == nullptr) {
		newnode->next = newnode;
		Head = newnode;
		return;
	}
	// last node

	Node* last = Head;
	while (last->next != Head) {
		last = last->next;       // if just one node, skipped and last is already initialised as Head
	}
	newnode->next = Head;
	last->next = newnode;
	Head = newnode;
}

void InsertInEnd(Node*& Head, int newval) {
	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = nullptr;

	// checking if the list is empty
	if (Head == nullptr) {
		newnode->next = newnode;
		Head = newnode;
		return;
	}

	// going to the last node to join newnode
	Node* last = Head;
	while (last->next != Head) {
		last = last->next;
	}
	last->next = newnode;
	newnode->next = Head;
}

void InsertAtPos(int pos, int newval, Node*& Head) {
	int len = CountList(Head);

	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = nullptr;

	// if trying to insert in the beginning of the list || pos == 1
	if (pos == 1) {
		InsertInBeginning(Head, newval);
		return;
	}

	// if trying to insert outside the range of the list
	if (pos <= 0 || pos > len+1) {                                            // error->len +1 not len as len means we cant insert at end
		cout << "ERROR. Enter position within range of the list !" << endl;
		return;
	}

	// If list is empty and pos > 1, invalid
	if (Head == nullptr && pos > 1) {
		cout << "ERROR: Empty list — can only insert at position 1." << endl;   // this is important
		return;
	}
	// traversing to node before it, at position -> pos - 1
	Node* prev = Head;
	for (int i = 1; i < pos - 1; i++) {
		prev = prev->next;
	}

	newnode->next = prev->next;
	prev->next = newnode;
}

// Deletions 

void DeleteFirstNode(Node*& Head) {

	// Empty List
	if (Head == nullptr) {
		cout << "list already empty!" << endl;
		return;
	}

	// One Node
	if (Head->next == Head) {
		delete Head;
		Head = nullptr;
		return;
	}

	Node* temp = Head;
	Node* last = Head;

	//finding last node
	while (last->next != Head) {
		last = last->next;
	}

	//updating Head pointer
	Head = Head->next;
	// making list circular
	last->next = Head;
	// deleting first node
	temp->next = nullptr;
	delete temp;
}	

void DeleteLastNode(Node*& Head) {

	// Empty List
	if (Head == nullptr) {
		cout << "List already empty !" << endl;
		return;
	}

	// One Node
	if (Head->next == Head) {
		DeleteFirstNode(Head);
		return;
	}

	// node before last node
	Node* second_last = Head;

	while (second_last->next->next != Head) {
		second_last = second_last->next;
	}  

	// not using 2 nodes prev and curr, traversing to one before last and manipulating the next pointers
	Node* last = second_last->next;

	second_last->next = last->next;
	last->next = nullptr;
	delete last;
}

// same way as in SLL and DLL, using curr and prev
void DeleteAtPos(int pos, Node*& Head) {
	
	int len = CountList(Head);

	// empty list
	if (Head == nullptr) {
		cout << "List is already empty" << endl;
		return;
	}

	// checking if deleting first Node
	if (pos == 1) {
		DeleteFirstNode(Head);
		return;
	}

	// checking if deleting within the range of the list
	if (pos <= 0 || pos > len) {
		cout << "Please enter position within the range of the list" << endl;
		return;
	}

	Node* prev = nullptr;
	Node* curr = Head;

	for (int i = 1; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;
	curr->next = nullptr;
	delete curr;
}



int main() {
	Node* head = nullptr;


	PrintList(head);

	cout << "\nInserting -->" << endl;
	InsertInBeginning(head, 1);
	InsertAtPos(2, 4, head);
	InsertAtPos(3, 9, head);
	InsertAtPos(4,16,head);
	InsertInEnd(head, 100);

	PrintList(head);
	cout << endl;
	cout << "number of elements: " << CountList(head) << endl;

	// cout << head->next->next->next->value << endl; ->  // print 16? ... yes --> checked for insert in end logic of getting last node from second last
	cout << "\nDeletions-->" << endl;

	DeleteFirstNode(head);
    DeleteLastNode(head);
	DeleteAtPos(2, head);

	PrintList(head);
	cout << endl;
	cout << "number of elements: " << CountList(head) << endl;


	return 0;
}