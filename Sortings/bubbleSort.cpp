#include <iostream>
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted, no need to check them
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the current element is greater than the next
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Example array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    bubbleSort(arr, n); // Call bubble sort

    // Print the sorted array
    cout << "Bubble Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Output: Bubble Sorted Array: 11 12 22 25 34 64 90
    return 0;
}
