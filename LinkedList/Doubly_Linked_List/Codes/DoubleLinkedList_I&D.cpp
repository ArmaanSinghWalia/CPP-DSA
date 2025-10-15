// Doubly Linked Lists
// Insertions, Deletions, And basic data structure operations (Traverse & Count)
// Much, Much tougher and practice demanding than SLL
// No Mistake Code : 27/07/25

// Revisited on : 15/10/25

// - ASWalia

#include <iostream>
using namespace std;

/*-------------------- NODE STRUCTURE --------------------*/

// Class representing a node in the doubly linked list
class Node {
public:
    int value;
    Node* prev;
    Node* next;

    // Constructor with value initialization
    Node(int v) {
        value = v;
        prev = next = nullptr;
    }

    // Default constructor
    Node() {
        value = 0;
        prev = next = nullptr;
    }
};


/*-------------------- DISPLAY & COUNT --------------------*/


// Display the list from head to end
void Display(Node* Head) {
    if (!Head) {
        cout << "Cannot display empty list" << endl;
        return;
    }

    while (Head) {
        cout << Head->value << " ";
        Head = Head->next;
    }
}

// Count the number of nodes in the list
int Count(Node* Head) {
    int c = 0;
    while (Head) {
        c++;
        Head = Head->next;
    }
    return c;
}


/*-------------------- INSERTIONS --------------------*/


// Insert a new node at the beginning
void InsertAtBeginning(Node*& Head, int newval) {
    Node* newnode = new Node(newval);
    newnode->next = Head;

    if (Head) {
        Head->prev = newnode;
    }

    Head = newnode;
}

// Insert a new node at the end
void InsertAtEnd(Node*& Head, int newval) {
    Node* newnode = new Node(newval);

    // Empty list case
    if (!Head) {
        Head = newnode;
        return;
    }

    // Traverse to last node
    Node* last = Head;
    while (last->next) {
        last = last->next;
    }

    last->next = newnode;
    newnode->prev = last;
}

// Insert a new node after a given node
void InsertAfter(Node* Prev, int newval) {
    if (!Prev) {
        cout << "Cannot insert after nullptr" << endl;
        return;
    }

    // If Prev is the last node
    if (!Prev->next) {
        InsertAtEnd(Prev, newval);
        return;
    }

    Node* newnode = new Node(newval);

    // Update pointers
    newnode->next = Prev->next;
    Prev->next->prev = newnode;
    Prev->next = newnode;
    newnode->prev = Prev;
}

// Insert a new node at a specific position (1-based)
void InsertAtPos(Node*& Head, int pos, int newval) {
    int size = Count(Head);

    // Invalid position
    if (pos <= 0 || pos > size + 1) {
        cout << "Enter a valid position value" << endl;
        return;
    }

    // Insert at beginning
    if (!Head || pos == 1) {
        InsertAtBeginning(Head, newval);
        return;
    }

    // Traverse to node before the desired position
    Node* prev = Head;
    for (int i = 1; i < pos - 1; i++) {
        prev = prev->next;
    }

    Node* newnode = new Node(newval);

    // Update pointers
    newnode->next = prev->next;
    prev->next->prev = newnode;
    newnode->prev = prev;
    prev->next = newnode;
}


/*-------------------- DELETIONS --------------------*/


// Delete the first node
void DeleteFirst(Node*& Head) {
    if (!Head) {
        cout << "Cannot perform deletion: list is empty" << endl;
        return;
    }

    Node* temp = Head;
    Head = Head->next;

    // Update new head's prev pointer
    if (Head) Head->prev = nullptr;

    delete temp;
}

// Delete the last node
void DeleteLast(Node*& Head) {
    if (!Head) {
        cout << "Cannot perform deletion: list is empty" << endl;
        return;
    }

    if (!Head->next) {
        DeleteFirst(Head);
        return;
    }

    Node* temp = Head;
    while (temp->next->next) {
        temp = temp->next;
    }

    Node* last = temp->next;
    temp->next = nullptr;
    delete last;
}

// Delete a node by value
void DeleteByValue(Node*& Head, int key) {
    if (!Head) {
        cout << "Cannot perform deletion: list is empty" << endl;
        return;
    }

    Node* temp = Head;

    // Head node matches
    if (temp->value == key) {
        Head = Head->next;
        if (Head) Head->prev = nullptr;
        delete temp;
        return;
    }

    // Search for node
    while (temp) {
        if (temp->value == key) {
            temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }

    cout << key << " not found in the linked list" << endl;
}

// Delete a node at a specific position (1-based)
void DeleteAtPos(Node*& Head, int pos) {
    int size = Count(Head);

    if (!Head) {
        cout << "Cannot perform deletion: list is empty" << endl;
        return;
    }

    if (pos <= 0 || pos > size) {
        cout << "Enter valid position to delete at" << endl;
        return;
    }

    if (pos == 1) {
        DeleteFirst(Head);
        return;
    }

    Node* prev = Head;
    for (int i = 1; i < pos - 1; i++) {
        prev = prev->next;
    }

    Node* curr = prev->next;
    prev->next = curr->next;

    if (curr->next) {
        curr->next->prev = prev;
    }

    delete curr;
}

// Delete all nodes and free memory
void DeleteAll(Node*& Head) {
    while (Head) {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
    }
}


/*-------------------- MAIN --------------------*/


int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Initial values and links
    head->value = 1; head->prev = nullptr; head->next = second;
    second->value = 2; second->prev = head; second->next = third;
    third->value = 3; third->prev = second; third->next = nullptr;

    cout << "Original list -->" << endl;
    Display(head);
    cout << "\nNumber of elements: " << Count(head) << endl << endl;

    cout << "Performing Insertions -->" << endl;
    InsertAtBeginning(head, 0);
    InsertAtEnd(head, 100);
    InsertAfter(second, 22);
    InsertAtPos(head, 3, 11);

    Display(head);
    cout << "\nNumber of elements: " << Count(head) << endl << endl;

    cout << "Performing Deletions -->" << endl;
    DeleteFirst(head);
    DeleteLast(head);
    DeleteAtPos(head, 2);
    DeleteByValue(head, 22);
    DeleteByValue(head, 100);

    Display(head);
    cout << "\nNumber of elements: " << Count(head) << endl << endl;

    cout << "Deleting all elements from main() -->" << endl;
    DeleteAll(head);

    Display(head);
    cout << "Number of elements: " << Count(head) << endl;

    return 0;
}
