#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int maxSize;

public:
    Stack(int size) {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return -1; // or some other error value
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void separateEvenOdd(Stack& input, Stack& evenStack, Stack& oddStack) {
    Stack tempStack(input.maxSize);
    
    while (!input.isEmpty()) {
        int value = input.pop();
        tempStack.push(value);

        if (value % 2 == 0) {
            evenStack.push(value);
        } else {
            oddStack.push(value);
        }
    }

    while (!tempStack.isEmpty()) {
        input.push(tempStack.pop());
    }
}

void printStack(Stack& s) {
    Stack tempStack(s.maxSize);
    while (!s.isEmpty()) {
        int value = s.pop();
        cout << value << " ";
        tempStack.push(value);
    }
    cout << endl;

    while (!tempStack.isEmpty()) {
        s.push(tempStack.pop());
    }
}

int main() {
    Stack inputStack(6);
    Stack evenStack(6);
    Stack oddStack(6);

    inputStack.push(10);
    inputStack.push(15);
    inputStack.push(22);
    inputStack.push(33);
    inputStack.push(40);
    inputStack.push(7);

    separateEvenOdd(inputStack, evenStack, oddStack);

    cout << "Even Stack: ";
    printStack(evenStack);
    
    cout << "Odd Stack: ";
    printStack(oddStack);

    return 0;
}
