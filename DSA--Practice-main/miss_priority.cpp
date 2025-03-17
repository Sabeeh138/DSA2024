#include <iostream>
#include <climits> // for INT_MIN and INT_MAX
using namespace std;

struct Item {
    int value;
    int priority;
};

Item pr[1000]; // Priority queue
int size_PQ = -1;

void enqueue(int value, int priority) {
    size_PQ++;
    pr[size_PQ].value = value;
    pr[size_PQ].priority = priority;
}

// Function to find the index of the element with the lowest priority (ascending)
int peekAscending() {
    int lowestPriority = INT_MAX;
    int ind = -1;

    for (int i = 0; i <= size_PQ; i++) {
        if (lowestPriority > pr[i].priority) {
            lowestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

// Function to find the index of the element with the highest priority (descending)
int peekDescending() {
    int highestPriority = INT_MIN;
    int ind = -1;

    for (int i = 0; i <= size_PQ; i++) {
        if (highestPriority < pr[i].priority) {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

// General dequeue function, takes a boolean flag for ascending or descending
void dequeue(bool ascending = true) {
    int ind = ascending ? peekAscending() : peekDescending();
    for (int i = ind; i < size_PQ; i++) {
        pr[i] = pr[i + 1];
    }
    size_PQ--;
}

int main() {
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(12, 3);
    enqueue(7, 1);

    // Ascending Priority Queue
    cout << "Ascending Order Priority Queue:" << endl;
    while (size_PQ >= 0) {
        cout << "Dequeued value: " << pr[peekAscending()].value << endl;
        dequeue(true);  // Passing true for ascending order
    }

    // Resetting queue for demonstration
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(12, 3);
    enqueue(7, 1);

    // Descending Priority Queue
    cout << "\nDescending Order Priority Queue:" << endl;
    while (size_PQ >= 0) {
        cout << "Dequeued value: " << pr[peekDescending()].value << endl;
        dequeue(false);  // Passing false for descending order
    }

    return 0;
}




