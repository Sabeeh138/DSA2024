/*
stacks using arrays
*/

#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int* arr; // dynamic array for stack

public:
    // Constructor to initialize the stack
    Stack(int size) {
        this->size = size;
        arr = new int[size];  // dynamic array allocation
        top = -1;             // initially, stack is empty
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow: Cannot push " << value << ". Stack is full." << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    // Function to remove the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop. Stack is empty." << endl;
            return -1;
        }
        return arr[top--];
    }
    
    // Function to return the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Function to display the stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5); // Create a stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    s.display();
    
    // Trying to push when the stack is full
    s.push(60); 

    cout << "Top element is: " << s.peek() << endl;

    cout << "Popped element is: " << s.pop() << endl;
    cout << "Popped element is: " << s.pop() << endl;

    s.display();
    
    return 0;
}
