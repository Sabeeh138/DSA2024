#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int an = mid - l + 1;
    int bn = r - mid;

    int a[an];
    int b[bn];

    for(int i = 0; i < an; i++){
        a[i] = arr[l + i];
    }
    for(int j = 0; j < bn; j++){
        b[j] = arr[mid + 1 + j];
}

int i = 0;
int j = 0;
int k = l;



}
void mergesort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    int mid = l + r;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}


int main(){
    int arr[] = {10,28,24,6,34,18,38,44};
    int n  = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,n-1);

    for(int i = 0;i < n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}