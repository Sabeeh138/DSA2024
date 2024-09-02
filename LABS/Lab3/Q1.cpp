#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert node at front
    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert node at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert node before a given value
    void insertBeforeValue(int value, int beforeValue) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            cout << "List is empty!" << endl;
            delete newNode;
            return;
        }

        if (head->data == beforeValue) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != beforeValue) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << beforeValue << " not found in the list!" << endl;
            delete newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Insert node after a given value
    void insertAfterValue(int value, int afterValue) {
        Node* temp = head;

        while (temp != nullptr && temp->data != afterValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << afterValue << " not found in the list!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete node from head
    void deleteFromHead() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete last node
    void deleteLastNode() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete node of a particular value
    void deleteNodeByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << value << " not found in the list!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Count number of nodes
    int countNodes() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtFront(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertBeforeValue(15, 20);
    list.insertAfterValue(25, 20);

    cout << "List: ";
    list.display();

    cout << "Number of nodes: " << list.countNodes() << endl;

    list.deleteFromHead();
    cout << "After deleting from head: ";
    list.display();

    list.deleteLastNode();
    cout << "After deleting last node: ";
    list.display();

    list.deleteNodeByValue(20);
    cout << "After deleting node with value 20: ";
    list.display();

    return 0;
}
