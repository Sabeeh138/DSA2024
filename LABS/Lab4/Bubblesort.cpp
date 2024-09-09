#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void print(int arr[], int size){
    for(int i = 0; i  < size; i++){
        cout<< arr[i]<<" "<<endl;
    }
}

int main(){
    int arr[]= {64,34,25,12,22,11,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted array: "; 
    print(arr, n);
    cout<<endl;
    bubblesort(arr, n);
    cout<<"Sorted array is: ";
    print(arr,n);
}
