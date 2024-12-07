#include <iostream>
using namespace std;

// Selection Sort Function
void selectionSort(int arr[], int n) {
    // Traverse the array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current index is the minimum

        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    // Example array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    selectionSort(arr, n); // Call selection sort

    // Print the sorted array
    cout << "Selection Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Output: Selection Sorted Array: 11 12 22 25 34 64 90
    return 0;
}
