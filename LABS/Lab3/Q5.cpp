#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->data < right->data) {
            left->next = merge(left->next, right);
            left->next->prev = left;
            left->prev = nullptr;
            return left;
        } else {
            right->next = merge(left, right->next);
            right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    }

    void split(Node* source, Node** frontRef, Node** backRef) {
        Node* fast;
        Node* slow;
        if (source == nullptr || source->next == nullptr) {
            *frontRef = source;
            *backRef = nullptr;
        } else {
            slow = source;
            fast = source->next;

            while (fast != nullptr) {
                fast = fast->next;
                if (fast != nullptr) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            *frontRef = source;
            *backRef = slow->next;
            slow->next = nullptr;
        }
    }

    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* left;
        Node* right;

        split(head, &left, &right);

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }

    void removeDuplicates() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* duplicate = current->next;
                current->next = duplicate->next;
                if (duplicate->next != nullptr) {
                    duplicate->next->prev = current;
                } else {
                    tail = current;
                }
                delete duplicate;
            } else {
                current = current->next;
            }
        }
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayList() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void sortList() {
        head = mergeSort(head);
        tail = head;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
        }
    }

    void removeDuplicatesFromSortedList() {
        removeDuplicates();
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertEnd(5);
    dll.insertEnd(3);
    dll.insertEnd(9);
    dll.insertEnd(3);
    dll.insertEnd(5);
    dll.insertEnd(7);
    dll.insertEnd(9);

    cout << "Original list: ";
    dll.displayList();

    dll.sortList();
    dll.removeDuplicatesFromSortedList();

    cout << "Sorted and deduplicated list: ";
    dll.displayList();

    return 0;
}
