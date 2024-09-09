#include <iostream>
using namespace std;


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

    
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {72, 89, 22, 56, 41, 13, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array: "; 
    print(arr, n);
    cout << endl;
    insertionSort(arr, n);
    cout << "Sorted array is: ";
    print(arr, n);
}
