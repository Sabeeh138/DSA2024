#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert node at the front
    void insertFront(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }


    void insertEnd(int val) {
        Node *newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    
    void insertBefore(int target, int val) {
        Node *current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        if (current != nullptr) {
            Node *newNode = new Node(val);
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != nullptr) {
                current->prev->next = newNode;
            } else {
                head = newNode;
            }
            current->prev = newNode;
        }
    }

    
    void insertAfter(int target, int val) {
        Node *current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        if (current != nullptr) {
            Node *newNode = new Node(val);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }
            current->next = newNode;
        }
    }

    void deleteHead() {
        if (head == nullptr) return;
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    
    void deleteEnd() {
        if (tail == nullptr) return;
        Node *temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

  
    void deleteValue(int val) {
        Node *current = head;
        while (current != nullptr && current->data != val) {
            current = current->next;
        }
        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
        }
    }

    // Display func
    void displayList() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.insertFront(5);
    dll.insertBefore(20, 15);
    dll.insertAfter(20, 25);
    dll.insertFront(0);

    cout << "Doubly Linked List: ";
    dll.displayList();

    dll.deleteHead();
    dll.deleteEnd();
    dll.deleteValue(15);

    cout << "List after deletions: ";
    dll.displayList();

    return 0;
}
