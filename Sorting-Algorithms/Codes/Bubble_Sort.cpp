#include <iostream>
using namespace std;

// ===============================================================
//                  BUBBLE SORT IMPLEMENTATION (ADAPTIVE)
// ===============================================================
// Author: <Your Name>
// Description:
//   - Reads an unsorted array from user input
//   - Sorts it using the Bubble Sort algorithm (adaptive version)
//   - Displays both unsorted and sorted arrays
// ===============================================================


// ---------------------------------------------------------------
// Function: Input
// Purpose : Take input for an unsorted array from the user
// ---------------------------------------------------------------
void Input(int arr[], int Size) {
    cout << "Enter an Unsorted array of elements -->\n" << endl;

    for (int i = 0; i < Size; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
}


// ---------------------------------------------------------------
// Function: Output
// Purpose : Display the elements of the array
// ---------------------------------------------------------------
void Output(int arr[], int Size) {
    for (int i = 0; i < Size; i++) {
        cout << "Element " << i + 1 << " : " << arr[i] << endl;
    }
    cout << endl;
}


// ---------------------------------------------------------------
// Function: BubbleSort
// Purpose : Sort the array using Bubble Sort algorithm
// Notes   :
//   - Works by repeatedly swapping adjacent elements
//   - Adaptive: Stops early if no swaps occur in a pass
//   - arr[] behaves like *arr (pointer to first element),
//     so changes made here reflect in main()
// ---------------------------------------------------------------
void BubbleSort(int arr[], int Size) {

    // Perform (Size - 1) passes
    for (int i = 0; i < Size - 1; i++) {

        int flag = 0; // Becomes 1 if any swap occurs

        // Each pass reduces comparisons by 1
        for (int j = 0; j < Size - 1 - i; j++) {

            // Swap if current element is greater than next
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }

        // If no swaps were done, the list is already sorted
        if (flag == 0)
            break;
    }
}


// ---------------------------------------------------------------
// Function: main
// Purpose : Entry point — reads size, inputs array, sorts, outputs
// ---------------------------------------------------------------
int main() {

    int arr[100];
    int size = 0;

    cout << "Enter size of array (max size = 100): ";
    cin >> size;

    // Validate input size
    if (size < 0 || size > 100) {
        cout << "Invalid size entered. Exiting program." << endl;
        return 0;
    }

    // Input and display unsorted array
    Input(arr, size);
    cout << "\nUnsorted array -->" << endl;
    Output(arr, size);

    // Sort array
    BubbleSort(arr, size);

    // Display sorted array
    cout << "Sorted array -->" << endl;
    Output(arr, size);

    return 0;
}
