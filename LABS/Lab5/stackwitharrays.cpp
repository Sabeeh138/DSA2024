#include <iostream>
using namespace std;

class Stack {
    int top;
    int maxSize;
    int* stackArray;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++top] = value;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return stackArray[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.size() << endl;

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
