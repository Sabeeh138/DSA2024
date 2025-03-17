#include <iostream>
using namespace std;

void selectionsort(int arr[], int n){
    for(int i = 0; i < n; i ++){
        int minindex = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minindex]){
                minindex= j;
            }
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
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
    selectionsort(arr, n);
    printarray(arr,n);
    return 0;
}