#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <climits>   // For INT_MIN
using namespace std;

// Function to perform counting sort on the array
void sort(vector<int> &arr) {
    auto n = arr.size();

    // Find the largest element in the array
    int largest = INT_MIN;
    for (auto i = 0; i < n; i++) {
        largest = max(largest, arr[i]);
    }

    // Create a count array to store the count of each unique element
    vector<int> count(largest + 1, 0);
    for (auto i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Reconstruct the sorted array using the count array
    auto j = 0;
    for (auto i = 0; i <= largest; i++) {
        while (count[i] > 0) {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
}

// Function to print the elements of the array
void printArr(const vector<int> &arr) {
    for (const auto &elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

// Main function to test the counting sort
int main() {
    vector<int> arr = {1, 4, 1, 3, 2, 4, 3, 7};
    sort(arr);
    printArr(arr);
    return 0;
}
