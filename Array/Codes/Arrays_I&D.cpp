// Arrays
// Full Implementation: Insertions, Deletions, Input, Traversal, Size

// Wrote My First Code Way Back In August
// Perfected And Refined For Clarity On 14/09/2025

// - ASWalia

#include <iostream>
using namespace std;

// Input Elements Into Array
void Input(int arr[], int Size) {

    for (int i = 0; i < Size; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
}

// Display Array Elements And Size
void Traverse(int arr[], int Size) {

    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nSize of array: " << Size << endl;
}

// Insert Element At A Given Position
// Pass By Reference To Update Size In Main
void Insert(int arr[], int& Size) {

    int element = 0, pos = 0;

    cout << "Enter value you want to insert: ";
    cin >> element;
    cout << "Enter position where you want to enter " << element << " : ";
    cin >> pos;

    // Check If Position Is Valid
    if (pos <= 0 || pos > Size + 1) {
        cout << "Error: Enter position within range of the array!\n";
        return;
    }

    // Check If Array Has Reached Maximum Capacity
    if (Size >= 100) {
        cout << "Error: Max size (100) reached. No further insertions possible.\n";
        return;
    }

    // Shift Elements Right To Make Space
    for (int i = Size - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = element;
    Size++;
}

// Delete Element From A Given Position
// Pass By Reference To Update Size In Main
void Delete(int arr[], int& Size) {

    int pos;

    cout << "Enter position you want to delete: ";
    cin >> pos;

    // Check If Position Is Valid
    if (pos <= 0 || pos > Size) {
        cout << "Error: Invalid position. Enter position within 0-" << Size - 1 << endl;
        return;
    }

    // Check If Array Is Empty
    if (Size == 0) {
        cout << "Error: Can't perform deletion on empty array.\n";
        return;
    }

    // Shift Elements Left To Fill Gap
    for (int i = pos - 1; i < Size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    Size--;
}

// Main Function
int main() {


    int arr[100];
    int size = 0;

    cout << "Enter the size of the array: ";
    cin >> size;

    // Validate Initial Size
    if (size > 100 || size < 0) {
        cout << "Error: Enter a valid size (0-100).\n";
        return 0;
    }

    cout << "\nEnter the original array -->\n";
    Input(arr, size);

    cout << "\nOriginal Array -->\n";
    Traverse(arr, size);

    // Insertion Operation
    cout << "\nInserting element into array -->\n";
    Insert(arr, size);
    cout << "\nArray after insertion -->\n";
    Traverse(arr, size);

    // Deletion Operation
    cout << "\nDeleting element from array -->\n";
    Delete(arr, size);
    cout << "\nArray after deletion -->\n";
    Traverse(arr, size);



    return 0;
}

