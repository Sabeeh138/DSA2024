/*
using all fucntionalities for doubly linked list
this is prac number 2
*/

#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    Node* prev;
    int data;

    Node(int value){
        next = prev = NULL;
        data = value;
    }
};

class DoublyLinkedlist{
private:
    Node* head;
    
public:
    DoublyLinkedlist(){
        head = NULL;
    }

    void insertathead(int data){
        Node* newnode = new Node(data);
        if(head != NULL){
            head->prev = newnode;
        }
        newnode->next = head;
        head = newnode;
    }

    void insertattail(int data){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }

    // Function to delete the first occurrence of a given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        // If the node to be deleted is the head
        if (head->data == value) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        // Traverse to find the node to delete
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        // If the value was not found
        if (temp == nullptr) {
            cout << "Value not found in the list." << endl;
            return;
        }

        // Update pointers and delete the node
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    // Function to print the list forward
    void printListForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to print the list backward
    void printListBackward() {
        if (head == nullptr) return;
        Node* temp = head;

        // Traverse to the end
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Traverse backward
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Function to search for a value in the list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

};
