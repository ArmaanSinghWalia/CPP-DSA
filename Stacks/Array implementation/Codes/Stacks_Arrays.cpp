#include <iostream>
using namespace std;

class Stack {
public:
    int* arr;   // Stores the elements
    int top;    // Index of the top element
    int size;   // Maximum number of elements allowed

    // Constructor - creates a stack with given size
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;  // Stack starts empty
    }

    // Add an element to the stack
    void push(int element) {
        if (size - top > 1) { // Check space
            top++;
            arr[top] = element;
            cout << "Pushed: " << element << endl;
        }
        else {
            cout << "Exception Thrown. " << element << " Caused Stack Overflow" << endl;
        }
    }

    // Remove the top element
    void pop() {
        if (top >= 0) { // Check if stack is not empty
            cout << "Popped: " << arr[top] << endl;
            top--;
        }
        else {
            cout << "Exception Thrown. Stack Overflow" << endl;
        }
    }

    // View the top element
    void peek() {
        if (top >= 0) {
            cout << "Top element is: " << arr[top] << endl;
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack st(5);  // Stack can hold up to 5 elements

    // Step 1: Add numbers 1, 2, 3
    cout << "\nAdding 1, 2, 3 to the stack...\n";
    st.push(1);
    st.push(2);
    st.push(3);

    // Step 2: See what's on top
    cout << "\nChecking top element...\n";
    st.peek();

    // Step 3: Remove top element
    cout << "\nRemoving top element...\n";
    st.pop();

    // Step 4: See what's on top now
    cout << "\nChecking top element again...\n";
    st.peek();

    // Step 5: Add more numbers to test overflow
    cout << "\nAdding 4, 5, 6; 7 to check overflow...\n";
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7); // This will overflow

    // Step 6: Final top check
    cout << "\nFinal top element...\n";
    st.peek();

    // Step 7: Check if stack is empty
    cout << "\nIs stack empty? " << endl;
    if (st.isEmpty()) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}
