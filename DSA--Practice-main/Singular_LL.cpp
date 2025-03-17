/*
 this code is for singly linked list all important functions
 Q1 of practice
*/#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    int data;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class SinglyLinkedlist{
private:
    Node* head;

public:
    SinglyLinkedlist(){
        head = NULL;
    }

    void insertathead(int data){
        Node* newnode = new Node(data);
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
    }

    // Function to insert a node after a given node value
    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Target node not found." << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete the first occurrence of a given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        // If the head node holds the value to be deleted
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
            cout << "Value not found in the list." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to search for a value in the list
    bool search(int data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to print the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to get the length of the list
    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }


};
