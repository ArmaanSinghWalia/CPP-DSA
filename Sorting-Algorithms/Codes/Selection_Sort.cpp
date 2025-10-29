// Selection Sort Implementation
// Cant be made adaptive like Bubble Sort as Linear Search implemented
// searches (n-1) + (n-2) .. + 1 times ----> O(n2) time complexity 
// -----------------------------------------------------------
// This program takes an unsorted array as input,
// applies the Selection Sort algorithm, and prints
// both the unsorted and sorted arrays.
// -----------------------------------------------------------

#include <iostream>
using namespace std;

// -----------------------------------------------------------
// Function: Input
// Purpose : Takes user input for array elements
// -----------------------------------------------------------
void Input(int arr[], int Size) {

	cout << "Enter an Unsorted array of elements -->\n" << endl;

	for (int i = 0; i < Size; i++) {
		cout << "Enter element " << i + 1 << " : ";
		cin >> arr[i];
	}
}

// -----------------------------------------------------------
// Function: Output
// Purpose : Displays array elements
// -----------------------------------------------------------
void Output(int arr[], int Size) {

	for (int i = 0; i < Size; i++) {
		cout << "Element " << i + 1 << " : " << arr[i] << endl;
	}
}

// -----------------------------------------------------------
// Function: SelectionSort
// Purpose : Sorts the array in ascending order
// Logic   : Finds the smallest element in each pass
//            and swaps it into its correct position
// -----------------------------------------------------------
// Note    : arr[] acts as a pointer to the first element,
//           so any modifications here directly update
//           the original array in main().
// -----------------------------------------------------------
void SelectionSort(int arr[], int Size) {

	// Outer loop: each pass places one element in its correct position
	for (int i = 0; i < Size - 1; i++) {

		// Assume the smallest element is at index i
		int minIndex = i;

		// Inner loop: find the index of the smallest element
		for (int j = i + 1; j < Size; j++) {
			if (arr[j] < arr[minIndex]) {
				// Update index of the smallest element found so far
				minIndex = j;
			}
		}

		// Swap the element at 'i' with the smallest element found
		// NOTE :
		//         arr[minIndex] is NOT a copy — it directly accesses the
		//         actual memory location in the array. Changing it here
		//         updates the real array in memory.
		// -------------------------------------------------------
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

// -----------------------------------------------------------
// Function: main
// Purpose : Driver code to execute Selection Sort
// -----------------------------------------------------------
int main() {

	int arr[100];
	int size = 0;

	cout << "Enter size of array (max size = 100): ";
	cin >> size;

	// Basic input validation
	if (size < 0 || size > 100) {
		cout << "Error: Invalid size entered!" << endl;
		return 0;
	}

	// Input & Display unsorted array
	Input(arr, size);
	cout << "\nUnsorted array -->" << endl;
	Output(arr, size);

	// Sort & Display sorted array
	cout << "\nSorted array -->" << endl;
	SelectionSort(arr, size);
	Output(arr, size);

	return 0;
}
