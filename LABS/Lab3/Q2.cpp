#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void printList() {
        Node* current = head;
        while (current) {
            scout << current->value << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void reverse() {
        Node* previous = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        while (current) {
            nextNode = current->next;
            current->next = previous;
            previous = current;      
            current = nextNode;      
        }
        head = previous;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList ll;

    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);

    cout << "Original List:" << endl;
    ll.printList();

    ll.reverse();

    cout << "Reversed List:" << endl;
    ll.printList();

    return 0;
}
