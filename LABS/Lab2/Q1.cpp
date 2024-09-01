#include <iostream>
using namespace std;

int main() {
    int* arr[3];
    int Size[3];
    int i, j;

    
    for (i = 0; i < 3; i++) {
        cout << "Row " << i + 1 << " size: ";
        cin >> Size[i];
        arr[i] = new int[Size[i]];
    }

    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < Size[i]; j++) {
            cout << "Enter row " << i + 1 << " element " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }

   
    for (i = 0; i < 3; i++) {
        int newSize = Size[i] + 5;  // resized to 5 more
        int* temp = new int[newSize];

    
        for (j = 0; j < Size[i]; j++) {
            temp[j] = arr[i][j];
        }

       
        for (j = Size[i]; j < newSize; j++) {
            temp[j] = 0;  // Default value new elementts
        }

        
        delete[] arr[i];
        arr[i] = temp;
        Size[i] = newSize;  // size updated here
    }


    cout << "\nArray elements after resizing:\n";
    for (i = 0; i < 3; i++) {
        cout << "Row " << i + 1 << ": ";
        for (j = 0; j < Size[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

   
    for (i = 0; i < 3; i++) {
        delete[] arr[i];
    }

    return 0;
}
