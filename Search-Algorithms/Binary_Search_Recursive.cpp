#include <iostream>
using namespace std;

// Input Array Elements
void ArrayInput(int arr[], int Size) {

    cout << "Enter sorted array of elements -->\n" << endl;

    for (int i = 0; i < Size; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
}

// Recursive Binary Search
// Searches for 'Key' in arr[Start..End]
// Returns index if found, -1 otherwise
int BinarySearch(int arr[], int Start, int End, int Key) {

    // Base condition: search range is invalid
    if (Start > End) {
        return -1;
    }

    // Calculate middle index
    int mid = Start + (End - Start) / 2;

    // Check if middle element is the key
    if (Key == arr[mid]) {
        return mid;
    }

    // If key is smaller, search left half
    else if (Key < arr[mid]) {
        return BinarySearch(arr, Start, mid - 1, Key);
    }

    // If key is larger, search right half
    else {
        return BinarySearch(arr, mid + 1, End, Key);
    }
}

// Check if Array is Sorted in Ascending Order
// Exits program if array is not sorted
void CheckSorted(int arr[], int Size) {

    for (int i = 0; i < Size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "\nArray is not sorted. Binary search won't work.\n";
            exit(0);
        }
    }
}

// Main Function
int main() {

    int arr[1000];   // Array storage
    int size = 0;    // Size of array
    int key = -1;    // Key to search

    // Input size of array
    cout << "Enter size of array: ";
    cin >> size;

    // Validate size
    if (size <= 0 || size > 1000) {
        cout << "Invalid array size. Must be between 1 and 1000.\n";
        exit(0);
    }

    // Input array elements
    ArrayInput(arr, size);

    // Ensure array is sorted
    CheckSorted(arr, size);

    // Input key to search
    cout << "\nEnter element to find: ";
    cin >> key;

    int start = 0;
    int end = size - 1;

    // Perform binary search and output result
    int index = BinarySearch(arr, start, end, key);
    cout << "\nElement found at index (-1 if not found): " << index << endl;

    return 0;
}
