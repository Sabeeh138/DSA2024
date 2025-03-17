#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index `i`
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = (2 * i) + 1; // Left child
    int right = (2 * i) + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Correct argument order: heapify(arr, n, largest)
    }
}

// Function to perform heap sort
void heapsort(int arr[], int n) {
    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); // Correct argument order: heapify(arr, n, i)
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Call heapify on the reduced heap
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapsort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
