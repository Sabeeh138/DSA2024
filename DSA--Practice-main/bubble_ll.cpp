#include <iostream>
using namespace std;


class Node {
public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        this->next = nullptr;
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
        if(head == NULL){
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next= newnode;
    }

    void Bubblesort(){
        if(head==NULL){
            return;
        }
        Node* end = NULL;
        bool swapped;

        do{
            swapped = false;
            Node* current = head;
            Node* prev = NULL;

            while(current-> next != end){
                if(current->data > current->next->data){
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data= temp;
                    swapped = true;
                }
                current = current->next;
            }
            end = current;
        }
        while(swapped);
    }

    void display(){
        Node* temp = head;
        while(temp->next != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }

    }
};