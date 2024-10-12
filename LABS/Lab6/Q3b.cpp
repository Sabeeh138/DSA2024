class CircularTicketQueue {
private:
    int front;
    int rear;
    int size;
    int capacity;
    int* queue;

public:
    CircularTicketQueue(int cap = 10) {
        front = -1;
        rear = -1;
        capacity = cap;
        size = 0;
        queue = new int[capacity];
    }

    ~CircularTicketQueue() {
        delete[] queue;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int passenger) {
        if (isFull()) {
            cout << "Queue is full. Cannot add passenger " << passenger << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // Circular movement
        queue[rear] = passenger;
        size++;
        if (front == -1) {
            front = 0;
        }
        cout << "Added passenger " << passenger << " to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Passenger " << queue[front] << " purchased a ticket and left the queue." << endl;
        front = (front + 1) % capacity;
        size--;
        if (size == 0) {  // Reset front and rear when the queue is empty
            front = -1;
            rear = -1;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};
