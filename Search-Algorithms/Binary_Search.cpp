#include <iostream>
using namespace std;

// Function: Input elements into the array
void arrayInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Function: Binary Search (Iterative)
// Returns the index of Key in arr[], or -1 if not found
int BinarySearch(int arr[], int size, int key) {

    int start = 0;
    int end = size - 1;

    while (start <= end) {

        // Calculate middle index (avoid overflow)
        int mid = start + (end - start) / 2;

        // Case 1: Key found
        if (arr[mid] == key) {
            return mid;
        }
        // Case 2: Key is smaller than middle, search left half
        else if (arr[mid] > key) {
            end = mid - 1;
        }
        // Case 3: Key is larger than middle, search right half
        else {
            start = mid + 1;
        }
    }

    // Key not found
    return -1;
}

int main() {

    const int MAX_SIZE = 1000;    // Maximum array size
    int arr[MAX_SIZE];
    int size = 0;
    int key = -1;

    // Input array size
    cout << "Enter size of array (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        cout << "Error: Invalid array size.\n";
        return 1;
    }

    // Input array elements
    arrayInput(arr, size);

    // Input key to search
    cout << "\nEnter element to find: ";
    cin >> key;

    // Perform binary search
    int position = BinarySearch(arr, size, key);

    // Display result
    if (position != -1) {
        cout << "Element found at index: " << position << endl;
    }
    else {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
