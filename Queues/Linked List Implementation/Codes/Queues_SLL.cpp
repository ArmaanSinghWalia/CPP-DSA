#include <iostream>
using namespace std;

// Node class: stores value and next pointer
class Node {
public:
    int value;
    Node* next;
    Node* front;  // pointer to front of queue
    Node* rear;   // pointer to rear of queue

    // Constructor
    Node(int v) {
        value = v;
        next = nullptr;
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: add element at the rear
    void Enqueue(int val) {
        Node* newnode = new Node(val);

        // If queue is empty
        if (!front || !rear) {
            front = rear = newnode;
            return;
        }

        // Insert at rear
        rear->next = newnode;
        rear = newnode;
    }

    // Dequeue: remove element from front
    void Dequeue() {
        // Underflow check
        if (!front) {
            cout << "UNDERFLOW: Queue is empty.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        cout << temp->value << " has been dequeued\n";
        delete temp;

        // If queue becomes empty, update rear
        if (!front) rear = nullptr;
    }

    // Peek: view front element without removing
    void Peek() {
        if (!front) {
            cout << "Cannot peek: Queue is empty.\n";
            return;
        }
        cout << "Front element: " << front->value << endl;
    }

    // Display all elements
    void Display() {
        if (!front) {
            cout << "Can not Display! Queue is empty!\n";
            return;
        }

        Node* temp = front;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Count number of elements
    int Count() {
        int size = 0;
        Node* temp = front;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    // Search for an element
    void SearchFor(int element) {
        Node* temp = front;
        while (temp) {
            if (temp->value == element) {
                cout << element << " is found in the queue.\n";
                return;
            }
            temp = temp->next;
        }
        cout << element << " not found in the queue.\n";
    }

    // Delete the entire queue
    void DeleteQueue() {
        cout << "\nDeleting queue...\n";
        while (front) {
            Node* curr = front;
            Node* next = front->next;
            delete curr;
            front = next;
        }
        rear = nullptr;
        cout << "Queue has been deleted.\n";
    }
};

// Main function to demonstrate queue operations
int main() {
    Node q(0);  // Queue object; initial value is unused

    cout << "Operations on empty queue:\n";
    q.Display();
    cout << "Number of elements: " << q.Count() << endl << endl;

    cout << "Performing enqueue:\n";
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    q.Display();
    cout << "Number of elements: " << q.Count() << endl;
    q.Peek();

    q.SearchFor(3);
    q.SearchFor(10);
    cout << endl;

    cout << "Performing dequeue operations (including underflow check):\n";
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();  // underflow

    q.Display();
    cout << "Number of elements: " << q.Count() << endl;
    q.Peek();
    cout << endl;

    cout << "Testing DeleteQueue() function:\n";
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Display();

    q.DeleteQueue();
    q.Display();

    return 0;
}
