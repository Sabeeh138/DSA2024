#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList(){
        head = NULL;
    }

    void insertattail(int data){
        Node* newnode = new Node(data);
        if(head==NULL){
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp= temp->next;
        }
        temp->next= newnode;
    }

    void insertion(){
        if (!head || !head->next) return;
        Node* sorted = NULL;
        Node* current = head;

        


    }


};