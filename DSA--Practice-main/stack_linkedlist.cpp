#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    int data;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
private:
    Node* top;

public:
    Stack(){
        top = NULL;
    }

    bool Isempty(){
        return (top == NULL);
    }

    void push(int data){
        Node* newnode = new Node(data);
        newnode->next = top;
        top = newnode;
        cout<<"data is pushed"<<endl;
    }

    int pop(){
        if(Isempty()){
            cout<<"underflow"<<endl;
            return -1;
        }
        int poppedvalue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedvalue;
    }
    
    int peek(){
        if(Isempty()){
            cout<<"Underflow"<<endl;
        }
        return top->data;
    }

    void display(){
        if(Isempty()){
            cout<<"error"<<endl;
        }
        Node* temp = top;
        while(temp->next != NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<"top element is: "<<s.peek()<<endl;
    s.pop();
    cout<<"top element after pop is: "<<s.peek()<<endl;
    cout<<"Stack size: "<<s.peek()<<endl;

    return 0;

}