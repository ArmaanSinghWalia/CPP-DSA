#include<iostream>
using namespace std;

class Node {
public:

	int data;
	Node* next;
};

void InsertInEnd(Node*& Head, int newval) {

	Node* newnode = new Node();
	newnode->data = newval;
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
		cout << n->data << " ";
		n = n->next;
	}
}

// returns head of reversed LL
Node* Reverse(Node* Head) {

	// BASE CASE
	if (Head == nullptr || Head->next == nullptr) {
		return Head;
	}

	Node* miniHead = Reverse(Head->next);
	Head->next->next = Head;  
	Head->next = nullptr;    
	return miniHead; // head keeps getting updated during recursion
}

Node* RecursiveReverse(Node* Head) {

	return Reverse(Head);
}

int main() {

	Node* head = nullptr;

	InsertInEnd(head, 1);
	InsertInEnd(head, 2);
	InsertInEnd(head, 3);
	InsertInEnd(head, 4);

	cout << "Displaying original list -->" << endl;
	Display(head);

	cout << endl;

	cout << "Reversing list recursively -->" << endl;
	head = RecursiveReverse(head);
	Display(head);

	return 0;
}


/*--------------LeetCode Solution---------------*/

/*

 ----- GIVEN -----

 /*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// BASE CASE
		if (head == nullptr || head->next == nullptr) {
			return head;
		}

		ListNode* miniHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return miniHead; // head keeps getting updated during recursion
	}
};

*/
