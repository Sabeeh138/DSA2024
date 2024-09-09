#include <iostream>
using namespace std;


void combSort(int arr[], int n) {
    const float shrink = 1.3;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        if (gap > 1) {
            gap = int(gap / shrink);
        }
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    combSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;

    return 0;
}
