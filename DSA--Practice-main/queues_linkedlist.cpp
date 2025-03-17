#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Queue{
private:
    Node* frontn;
    Node* rearn;
    int currentsize;

public:
    Queue(){
        frontn = NULL;
        rearn = NULL;
        currentsize = 0;
    }

    void enqueue(int value){
        Node* newnode = new Node(value);
        if(Isempty()){
            cout<<"Queue is in underflow"<<endl;
            frontn = rearn = newnode; //front rear both points to the newnode if the queue is empty
        }
        else {
            rearn->next = newnode;
            rearn = newnode;
        }
        currentsize++;
    }

    void dequeue(){
        if(Isempty()){
            cout<<"queue is in underflow, please return"<<endl;
            return;
        }
        Node* temp = frontn;
        frontn = frontn->next;
        delete temp;
        currentsize--;

        if(Isempty()){
            rearn = NULL;
        }
    }

    int front(){
        if(Isempty()){
            cout<<"queue is in underflow"<<endl;
            return -1;
        }
        return frontn->data;
    }
    
    int rear(){
        if(Isempty()){
            cout<<"queue is in underflow"<<endl;
            return -1;
        }
        return rearn->data;
    }

    bool Isempty(){
        return (currentsize == 0);
    }

    int size(){
        return currentsize;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout<<"front element is: "<<q.front()<<endl;
    cout<<"back element is: "<<q.rear()<<endl;

    q.dequeue();
    cout<<"front element after pop"<<q.front()<<endl;
    cout<<"size of the element is: "<<q.size()<<endl;
    return 0;
}
    