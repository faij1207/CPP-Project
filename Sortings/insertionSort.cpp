#include <iostream>
using namespace std;

// Insertion Sort Function
void insertionSort(int arr[], int n) {
    // Iterate over the array from the second element to the last
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Element to be placed in the correct position
        int j = i - 1;

        // Shift elements that are greater than the key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place the key in its correct position
    }
}

int main() {
    // Example array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    insertionSort(arr, n); // Call insertion sort

    // Print the sorted array
    cout << "Insertion Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Output: Insertion Sorted Array: 11 12 22 25 34 64 90
    return 0;
}
