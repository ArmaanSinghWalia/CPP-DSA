#include <iostream>
using namespace std;

// Function to take input for the array
void arrayInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Function to perform linear search
void linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "\nElement found at index: " << i << endl;
            return;
        }
    }
    cout << "\nElement not found" << endl;
}

int main() {
    int arr[1000];    // Maximum array size
    int size = 0;
    int key = -1;

    // Input array size
    cout << "Enter size of array (max 1000): ";
    cin >> size;

    // Take array elements as input
    arrayInput(arr, size);

    // Input element to search
    cout << "\nEnter element to find: ";
    cin >> key;

    // Perform linear search
    linearSearch(arr, size, key);

    return 0;
}
