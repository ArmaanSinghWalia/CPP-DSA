// Stack implemented by arrays.
// Full Implementation: Push, Pop, Peek, isEmpty
// Revisted on 15.09.25 
// Added : Display(), Count(), SearchFor(int key), checkEmpty(bool status), ClearStack(), ~Stack() {Destructor}

// - ASWalia

#include <iostream>
using namespace std;

// Array-Based Stack Implementation
class Stack {
public:
    int* Arr;   // Pointer to dynamically allocated array
    int Size;   // Maximum capacity of stack
    int Top;    // Index of top element (-1 when empty)

    // Constructor: Initialize stack with given size
    Stack(int s) {
        Size = s;
        Arr = new int[s];
        Top = -1;
    }

    // Push: Add element to the top
    void push(int element) {
        if (Top == Size - 1) {
            cout << "Error: Stack overflow. Cannot push " << element << endl;
            return;
        }
        Top++;
        Arr[Top] = element;
    }

    // Pop: Remove top element
    void pop() {
        if (Top == -1) {
            cout << "Error: Stack underflow. Cannot pop." << endl;
            return;
        }
        int temp = Arr[Top];
        Top--;
        cout << temp << " has been popped from the stack" << endl;
    }

    // Peek: View top element
    void peek() {
        if (Top == -1) {
            cout << "Error: Stack is empty. Cannot peek." << endl;
            return;
        }
        cout << "Topmost element: " << Arr[Top] << endl;
    }

    // Display: Print all elements from top to bottom
    void Display() {
        if (Top == -1) {
            cout << "Stack is empty. Nothing to display." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = Top; i >= 0; i--) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    // Count: Number of elements in stack
    void Count() {
        int count = Top + 1;
        cout << "Size of stack: " << count << endl;
    }

    // Search: Find element and print its position (1-based from bottom)
    void SearchFor(int key) {
        for (int i = Top; i >= 0; i--) {
            if (Arr[i] == key) {
                cout << "Element " << key << " found at position: " << i + 1 << endl;
                return;
            }
        }
        cout << "Element " << key << " not found in the stack" << endl;
    }

    // Check if stack is empty (helper function for main)
    bool isEmpty() {
        return Top == -1;
    }

    void checkEmpty(bool status) {
        if (status)
            cout << "Stack has no elements" << endl;
        else
            cout << "Stack is not empty" << endl;
    }

    // Clear stack
    void ClearStack() {
        Top = -1;
        cout << "Stack has been reset" << endl;
    }

    // Destructor: free memory
    ~Stack() {
        delete[] Arr;
        cout << "Stack memory freed from heap" << endl;
    }
};

// Main function to test stack
int main() {
    Stack s(5); // Initialize stack of size 5

    cout << "Operations on empty stack:" << endl;
    s.pop();
    s.peek();
    s.checkEmpty(s.isEmpty());
    s.Display();
    s.Count();
    cout << endl;

    cout << "Pushing elements and checking overflow:" << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6); // Overflow
    s.peek();
    s.checkEmpty(s.isEmpty());
    s.Display();
    s.SearchFor(3);
    s.SearchFor(10);
    s.Count();
    cout << endl;

    cout << "Popping elements and checking underflow:" << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop(); // Underflow
    s.peek();
    s.checkEmpty(s.isEmpty());
    s.Display();
    s.Count();
    cout << endl;

    cout << "Resetting stack:" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.Display();
    s.Count();
    s.ClearStack();
    s.checkEmpty(s.isEmpty());
    s.Display();
    s.Count();
    cout << endl;

    return 0;
}



