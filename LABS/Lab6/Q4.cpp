//took help from chatgpt and used stack library since the code
//was getting very lengthy

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void enqueue(int x) {
        stack1.push(x);
        cout << "Enqueued " << x << " to the queue." << endl;
    }

    void dequeue() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        cout << "Dequeued " << stack2.top() << " from the queue." << endl;
        stack2.pop();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    q.dequeue();

    q.enqueue(40);

    cout << "Front element is: " << q.front() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
