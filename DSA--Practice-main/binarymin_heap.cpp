#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;       // Pointer to the heap array
    int capacity;    // Maximum capacity of the heap
    int size;        // Current size of the heap

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap overflow! Cannot insert " << value << endl;
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMax() {
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    int getMax() {
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    void displayHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap(10);

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);

    cout << "Heap after insertions: ";
    maxHeap.displayHeap();

    cout << "Maximum element: " << maxHeap.getMax() << endl;

    cout << "Extracted max: " << maxHeap.extractMax() << endl;

    cout << "Heap after extracting max: ";
    maxHeap.displayHeap();

    return 0;
}
