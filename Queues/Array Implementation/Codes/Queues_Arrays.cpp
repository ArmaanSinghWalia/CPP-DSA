// Stack implemented by arrays: Core Operations and Utility Functions
// Endless procrastination finally ended.
// Overestimated toughness.
// Pushed on September 19th, 2025.


// - ASWalia

#include <iostream>
using namespace std;

// Queue Implementation Using Arrays (Linear Queue)
class Queue {
public:
    int Size;   // Maximum size of queue
    int* Arr;   // Array to store elements
    int Front;  // Points to front element
    int Rear;   // Points to last element

    // Constructor
    Queue(int s) {
        Size = s;
        Arr = new int[Size];
        Front = -1;
        Rear = -1;
    }

    // Enqueue: Insert element at the end
    void enqueue(int element) {
        if (Rear == Size - 1) {
            cout << "Error: Overflow! " << element << " cannot be enqueued.\n";
            return;
        }

        Rear++;
        Arr[Rear] = element;

        if (Front == -1) {
            Front = 0; // First element added
        }
    }

    // Dequeue: Remove element from the front
    void dequeue() {
        if (Rear == -1 || Front > Rear) {
            cout << "Error: Underflow! Queue is empty, cannot dequeue.\n";
            return;
        }

        int temp = Arr[Front];
        Front++;
        cout << temp << " has been dequeued.\n";
    }

    // Peek: Show the front element
    void peek() {
        if (Front > Rear || Rear == -1) {
            cout << "Error: Queue is empty, nothing to peek.\n";
            return;
        }
        cout << "Front element: " << Arr[Front] << endl;
    }

    // Print all elements
    void printQueue() {
        if (Front > Rear || Rear == -1) {
            cout << "Queue is empty, nothing to display.\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = Front; i <= Rear; i++) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    // Count: Return number of elements in queue
    int Count() {
        if (Front > Rear || Rear == -1) {
            cout << "Queue is empty.\n";
            return 0;
        }
        return Rear - Front + 1;
    }

    // Search for an element
    void Searchfor(int element) {
        if (Front > Rear || Rear == -1) {
            cout << "Queue is empty! Cannot search for " << element << ".\n";
            return;
        }

        for (int i = Front; i <= Rear; i++) {
            if (Arr[i] == element) {
                cout << element << " found at position " << i + 1 << ".\n";
                return;
            }
        }
        cout << element << " not found in the queue.\n";
    }
};

// Main Function
int main() {
    Queue q(3);

    cout << "Enqueue & Overflow Test\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);  // Overflow
    q.printQueue();
    q.peek();
    cout << "Number of elements: " << q.Count() << endl << endl;

    cout << "Searching for elements 2 and 10\n";
    q.Searchfor(2);
    q.Searchfor(10);
    cout << endl;

    cout << "Dequeue & Underflow Test\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();   // Underflow
    q.printQueue();
    q.peek();
    cout << "Number of elements: " << q.Count() << endl;

    return 0;
}

