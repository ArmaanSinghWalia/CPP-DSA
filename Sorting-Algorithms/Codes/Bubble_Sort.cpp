#include <iostream>
using namespace std;

// ===============================================================
//                  BUBBLE SORT IMPLEMENTATION (ADAPTIVE)
// ===============================================================
// Description:
//   - Reads an unsorted array from user input
//   - Sorts it using the Bubble Sort algorithm (adaptive version)
//   - Displays both unsorted and sorted arrays
//   - Tracks and displays the number of swaps in each pass
// ===============================================================


void Input(int arr[], int Size) {
    cout << "Enter an Unsorted array of elements -->\n" << endl;

    for (int i = 0; i < Size; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
}

void Output(int arr[], int Size) {
    for (int i = 0; i < Size; i++) {
        cout << "Element " << i + 1 << " : " << arr[i] << endl;
    }
    cout << endl;
}

// ===============================================================
//   BubbleSort()
//   Notes   :
//     - Works by repeatedly swapping adjacent elements
//     - Adaptive: Stops early if no swaps occur in a pass
//     - Tracks and displays number of swaps per pass
// ===============================================================

void BubbleSort(int arr[], int Size) {

    int passCount = 0;  // Track number of passes for display

    // Perform (Size - 1) passes
    for (int i = 0; i < Size - 1; i++) {

        int flag = 0;      // Becomes 1 if any swap occurs
        int swapCount = 0; // Counts swaps in this pass

        // Each pass reduces comparisons by 1
        for (int j = 0; j < Size - 1 - i; j++) {

            // Swap if current element is greater than next
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = 1;        // A swap occurred
                swapCount++;     // Increment swap counter
            }
        }

        passCount++;

        // Display swaps for this pass
        cout << "Pass " << passCount << " --> Number of swaps: "
            << swapCount << endl;

        // If no swaps were done, the list is already sorted
        if (flag == 0)
            break;
    }

    cout << endl; // Add a newline after all passes
}

// ---------------------------------------------------------------

int main() {

    int arr[100];
    int size = 0;

    cout << "Enter size of array (max size = 100): ";
    cin >> size;

    // Validate input size
    if (size <= 0 || size > 100) {
        cout << "Invalid size entered. Exiting program." << endl;
        return 0;
    }

    // Input and display unsorted array
    Input(arr, size);
    cout << "\nUnsorted array -->" << endl;
    Output(arr, size);

    // Sort array (with swap tracking)
    cout << "Sorting array using Bubble Sort -->\n" << endl;
    BubbleSort(arr, size);

    // Display sorted array
    cout << "Sorted array -->" << endl;
    Output(arr, size);

    return 0;
}
