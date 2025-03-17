#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;        // Array to store the queue elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int cap;         // Capacity of the queue
    int currentsize; // Current number of elements in the queue

public:
    // Constructor to initialize the queue with a given size
    Queue(int size) {
        arr = new int[size];
        front = 0;
        rear = -1;
        cap = size;
        currentsize = 0;
    }

    // Destructor to free the allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (currentsize == cap) {
            cout << "Queue overflow, cannot add element" << endl;
            return;
        }
        rear = (rear + 1) % cap; // Circular increment of rear
        arr[rear] = value;
        currentsize++;
    }

    // Function to remove the front element from the queue
    void dequeue() {
        if (empty()) {
            cout << "Queue underflow, cannot remove any element" << endl;
            return;
        }
        front = (front + 1) % cap; // Circular increment of front
        currentsize--;
    }

    // Function to return the front element of the queue
    int frontindex() {
        if (empty()) {
            cout << "Queue is empty, no front element" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to return the rear element of the queue
    int back() {
        if (empty()) {
            cout << "Queue is empty, no rear element" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Function to check if the queue is empty
    bool empty() {
        return (currentsize == 0);
    }

    // Function to get the current size of the queue
    int size() {
        return currentsize;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.frontindex() << endl;
    cout << "Back element is: " << q.back() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.frontindex() << endl;
    cout << "Size of the queue: " << q.size() << endl;

    return 0;
}
