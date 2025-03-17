#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i = 0; i < n -1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j]>arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printarray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,24,543,123,44,212,12,14,32,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"original array is: \n";
    printarray(arr, n);

    cout<<"sorted array is: \n";
    bubblesort(arr, n);
    printarray(arr,n);
    return 0;
}