#include <iostream>
#include <vector>

using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}


void countingSort(int arr[], int n, int exp, bool ascending) {
    int output[n]; // Output array to store sorted numbers temporarily
    int count[10] = {0}; // There are 10 possible digits (0-9)

        for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    if (ascending) {
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
    } else {
        for (int i = 8; i >= 0; i--)
            count[i] += count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }


    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixSort(int arr[], int n, bool ascending) {
    int maxVal = getMax(arr, n); // Get the maximum value in the array to know the number of digits

        for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp, ascending);
}

int main() {
    int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    cout << "Original array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    
    radixSort(arr, n, true);
    cout << "\nSorted array in ascending order:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    
    radixSort(arr, n, false);
    cout << "\nSorted array in descending order:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
