#include<iostream>
using namespace std;

class Node {
public:

	int value;
	Node* next;
};

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

void Display(Node* n) {

	if (!n) {
		cout << "Cant display an empty list" << endl;
		return;
	}
	while (n) {
		cout << n->value << " ";
		n = n->next;
	}
}

Node* IterativeReverse(Node* Head) {

	Node* prev = nullptr;
	Node* curr = Head;
	Node* forward = nullptr;  // Initialising
	while (curr) {
		forward = curr->next; 
		curr->next = prev;
		prev = curr;
		curr = forward;
	}
	return prev;
}

int main() {

	Node* head = nullptr;

	cout << "Displaying an empty list -->" << endl;
	Display(head);

	cout << endl;

	cout << "Inserting 1 -> 2 -> 3 -> 4 in the list" << endl;

	InsertAtEnd(head, 1);
	InsertAtEnd(head, 2);
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 4);

	cout << endl;

	cout << "Original list -->" << endl;
	Display(head);

	cout << endl;

	cout << "Reversing the linked list iteratively -->" << endl;
	
	head = IterativeReverse(head);
	Display(head);

	cout << endl;

	return 0;
}


/*--------------LeetCode Solution---------------*/

/*

 ----- GIVEN -----
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 -----------------

class Solution {
public:

	void Display(ListNode* n) {
		if (!n) {
			cout << "cant display an empty list" << endl;
			return;
		}
		while (n) {
			cout << n->val << " ";
			n = n->next;
		}
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		ListNode* forward = nullptr;
		while (curr) {
			forward = curr->next;
			curr->next = prev;
			prev = curr;
			curr = forward;
		}
		// Display(prev);  ( 14ms vs 0ms)
		return prev;
	}
};

*/
