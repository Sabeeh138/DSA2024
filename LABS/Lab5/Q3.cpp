#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int n)
    {
        val = n;
        next = nullptr;
    };
};

class SinglyLinkedList
{
    Node *Head;

public:
    SinglyLinkedList()
    {
        Head = nullptr;
    }

    void append(int val)
    {
        if (Head == nullptr)
        {
            Head = new Node(val);
        }
        else
        {
            Node *currentPtr = Head;
            // traversing the linked list
            while (currentPtr->next != nullptr)
            {
                currentPtr = currentPtr->next;
            }
            currentPtr->next = new Node(val);
        }
    }

    void printList()
    {
        Node *current = Head;
        while (current != nullptr)
        {
            cout << current->val << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    Node *reverseRecursively(Node *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            return node;
        }
        Node *newHead = reverseRecursively(node->next); // reverse the rest of the list
        node->next->next = node;                        // next node should point to the current
        node->next = nullptr;                           // current node should point to NULL

        return newHead;
    }

    void reverseList()
    {
        Head = reverseRecursively(Head);
    }
};

int main()
{
    SinglyLinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    cout << "original List: " << endl;
    list.printList();
    cout << "reversed list: " << endl;
    list.reverseList();
    list.printList();
}
