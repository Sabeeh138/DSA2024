#include <iostream>
using namespace std;

class Maxheap{
private:
    int* heap;
    int capacity;
    int size;

public:
//constructor for maxheap
    Maxheap(int cap){
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }
//to free memory extra mem
    ~Maxheap(){
        delete[] heap;
    }

    int parent(int i){
        return(i - 1)/2;
    }

    int leftchild(int i ){
        return (2 * i) + 1;
    }

    int rightchild(int i){
        return (2 * i) + 2;
    }

    void insert(int key){
        if(size == capacity){
            cout<<"heap is in overflow, please return"<<endl;
            return;
        }

        size++;
        int i = size - 1;
        heap[i] = key;
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int extractMax(){
        if(size <= 0){
            return 0;
        }
        if (size == 1){
            size--;
            return heap[0];
        }
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        return root;
    }

    void heapify(int i){
        int largest = i;
        int left = leftchild(i);
        int right = rightchild(i);

        //comparision with leftchild
        if(left < size && heap[left] > heap[largest]){
            largest = left;
        }
        //comparision with rightchild
        if(right < size && heap[right] > heap[largest]){
            largest = right;
        }
        //swap and continue heapify if root is not largest
        if(largest != i){
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
//func to get root without removing it
    int getmax(){
        return (size > 0) ? heap[0] : INT8_MIN;
    }
//print the heapmax
    void printHeap(){
        for(int i = 0; i < size; ++i){
            cout<<heap[i]<< " ";
        }
        cout<<endl;
    }
};

int main() {
    Maxheap maxHeap(10); // Create a max heap with a capacity of 10

    // Insert elements into the heap
    maxHeap.insert(15);
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(17);
    maxHeap.insert(8);

    cout << "Heap after inserting elements: ";
    maxHeap.printHeap(); // Print the current state of the heap

    cout << "Maximum element (without removing): " << maxHeap.getmax() << endl;

    // Extract the maximum element
    cout << "Extracted max: " << maxHeap.extractMax() << endl;

    cout << "Heap after extracting max: ";
    maxHeap.printHeap(); // Print the heap after extraction

    // Insert more elements
    maxHeap.insert(25);
    maxHeap.insert(30);

    cout << "Heap after inserting more elements: ";
    maxHeap.printHeap();

    // Extract another maximum element
    cout << "Extracted max: " << maxHeap.extractMax() << endl;

    cout << "Heap after extracting another max: ";
    maxHeap.printHeap();

    return 0;
}
