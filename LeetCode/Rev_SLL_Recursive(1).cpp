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

// Helper function for recursion
void Reverse(Node*& HEAD, Node* Prev, Node* Curr) {
	if (!Curr) {
		HEAD = Prev;              // when end of list is reached, update head.
		return;
	}
	Node* forward = Curr->next;
	Curr->next = Prev;
	Reverse(HEAD, Curr, forward);
}

Node* RecursiveReverse(Node* Head) {

	// For empty SLL    || one element in SLL
	if (Head == nullptr || Head->next == nullptr) {
		return Head;
	}
	Node* prev = nullptr;
	Node* curr = Head;
	Reverse(Head, prev, curr);
	return Head;
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
	// Solving by Recursion
	void Reverse(ListNode*&Head,ListNode*Prev,ListNode*Curr) {
		// BASE CONDITION
		if(!Curr) {
			Head = Prev;
			return;
		}
		ListNode* Forward = Curr->next;
		Curr->next = Prev;
		Reverse(Head,Curr,Forward);
	}
	ListNode* reverseList(ListNode* head) {
	  // no element || one element
		if(!head || !head->next) {
			return head;
		}
		ListNode* prev = nullptr;
		ListNode* curr = head;
		Reverse(head,prev,curr);
		return head;
		// prev wont be returned here as its just a helper ptr in recursion and its value doesnt get updated like in the iterative version of this problem
	}
};

*/
