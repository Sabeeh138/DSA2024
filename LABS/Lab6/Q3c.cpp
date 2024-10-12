class Node {
public:
    int passenger;
    Node* next;

    Node(int value) {
        passenger = value;
        next = nullptr;
    }
};

class LinkedListTicketQueue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    LinkedListTicketQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int passenger) {
        Node* newNode = new Node(passenger);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Added passenger " << passenger << " to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        cout << "Passenger " << front->passenger << " purchased a ticket and left the queue." << endl;
        front = front->next;
        delete temp;
        size--;
        if (isEmpty()) {
            rear = nullptr;  // Reset rear when the queue is empty
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Current queue: ";
        while (temp != nullptr) {
            cout << temp->passenger << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
