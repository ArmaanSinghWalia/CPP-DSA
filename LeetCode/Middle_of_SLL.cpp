// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Pushed on 4:45am, 21 October 2025
// First code to work on the first time
// BEST way to code --> visualise and dry run

#include<iostream>
using namespace std;

class Node {
public:

	int value;
	Node* next;
};

int Count(Node* n) {
	int c = 0;
	while (n) {
		c++;
		n = n->next;
	}
	return c;
}

Node* middleNode(Node* Head) {

	int size = Count(Head);
	int mid = 0;

	// even size
	if (size % 2 == 0) {
		mid = (size / 2) + 1;
	}
	// odd size
	else {
		mid = (size + 1) / 2;
	}

	for (int i = 1; i < mid; i++) {
		Head = Head->next;
	}
	return Head;
}

void InsertAtBeginning(Node*& Head, int newval) {

	Node* newnode = new Node();
	newnode->value = newval;
	newnode->next = Head;
	Head = newnode;
}

void Display(Node* n) {
	while (n) {
		cout << n->value << " ";
		n = n->next;
	}
}

int main() {

	Node* head = nullptr;

	InsertAtBeginning(head, 5);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 0);

	cout << "OG list -->" << endl;
	Display(head);

	Node* newHead = middleNode(head);

	cout << "\nList from middle element -->" << endl;
	Display(newHead);

	return 0;
}


/*--------------LeetCode Solution---------------*/

/*

// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		// counting number of nodes
		ListNode* temp = head;
		int size = 0, mid = 0;

		while (temp) {
			size++;
			temp = temp->next;
		}

		// even number of elements
		if (size % 2 == 0) {
			mid = (size / 2) + 1;
		}
		// odd number of elements
		else {
			mid = (size + 1) / 2;
		}

		// moving head ahead
		for (int i = 1; i < mid; i++) {
			head = head->next;
		}
		return head;

	}
};


*/
