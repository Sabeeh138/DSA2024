#include <iostream>
using namespace std;

void insertionsort(int arr[], int n){
    for(int i = 0; i< n; i++){
        int key = arr[i];
        int j = i - 1;
        while( j>= 0 && arr[j]> key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionsort(arr, n);
    printarray(arr,n);
    return 0;
}