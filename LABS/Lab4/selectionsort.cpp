#include <iostream>
using namespace std;

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
    selectionsort(arr, n);
    cout << "Sorted array is: ";
    print(arr, n);
}
