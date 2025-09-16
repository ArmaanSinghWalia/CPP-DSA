#include<iostream>
using namespace std;

// Node structure for Stack
class Node {
public:
    int value;
    Node* next;
};

// Count number of elements in stack
int Count(Node* Top) {
    int size = 0;
    while (Top != nullptr) {
        size++;
        Top = Top->next;
    }
    return size;
}

// Display all elements in stack
void Display(Node* Top) {
    if (Top == nullptr) {
        cout << "Error: Cannot display, stack is empty.\n";
        return;
    }
    while (Top != nullptr) {
        cout << Top->value << " ";
        Top = Top->next;
    }
    cout << endl;
}

// Push element onto stack
void push(Node*& Top, int element) {
    Node* newnode = new Node();
    newnode->value = element;
    newnode->next = Top;
    Top = newnode;
}

// Pop element from stack
void pop(Node*& Top) {
    if (Top == nullptr) {
        cout << "Error: Underflow. Cannot perform pop.\n";
        return;
    }
    Node* temp = Top;
    Top = Top->next;
    cout << "Popping: " << temp->value << " from the stack.\n";
    delete temp;
}

// Peek at topmost element
void peek(Node* Top) {
    if (Top == nullptr) {
        cout << "Error: Cannot peek, stack is empty.\n";
        return;
    }
    cout << "Top element: " << Top->value << endl;
}

// Search for element in stack
void SearchFor(Node* Top, int element) {
    if (Top == nullptr) {
        cout << "Error: Cannot search, stack is empty.\n";
        return;
    }
    while (Top != nullptr) {
        if (Top->value == element) {
            cout << element << " found in the stack.\n";
            return;
        }
        Top = Top->next;
    }
    cout << element << " not found in the stack.\n";
}

// Clear entire stack (free memory)
void ClearStack(Node*& Top) {
    cout << "\nClearing stack memory...\n";
    while (Top != nullptr) {
        Node* temp = Top;
        Top = Top->next;
        delete temp;
    }
    cout << "Stack memory has been cleared.\n";
}

// Main function (driver code)
int main() {
    Node* top = nullptr;

    // Empty stack operations
    cout << "Operating on an empty stack -->\n";
    peek(top);
    cout << "Size of stack: " << Count(top) << endl;
    Display(top);

    // Push operations
    cout << "\nPushing elements...\n";
    push(top, 1);
    push(top, 2);
    push(top, 3);

    peek(top);
    cout << "Size of stack: " << Count(top) << endl;
    Display(top);

    // Search operations
    SearchFor(top, 2);   // Found
    SearchFor(top, 10);  // Not Found

    // Pop operations
    cout << "\nPopping elements and checking underflow -->\n";
    pop(top);
    pop(top);
    pop(top);
    pop(top); // Underflow

    // ClearStack test
    cout << "\nChecking ClearStack function -->\n";
    push(top, 1);
    push(top, 2);
    push(top, 3);

    cout << "Size of stack: " << Count(top) << endl;
    ClearStack(top);
    cout << "Size of stack: " << Count(top) << endl;

    return 0;
}
