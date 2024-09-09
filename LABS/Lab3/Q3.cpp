#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    // Default constructor
    Node() : data(0), next(nullptr) {}

    // Parameterized constructor
    Node(int val) : data(val), next(nullptr) {}

    // Friend class to access private members
    friend class TestLinkList;
};

class TestLinkList
{
private:
    Node *head;

public:
    // Default constructor
    TestLinkList() : head(nullptr) {}

    // Parameterized constructor
    TestLinkList(Node *n) : head(n) {}

    // Insert a new node at the start
    void insert_start(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Segregate even and odd nodes
    void segregateEvenOdd()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // No segregation needed for empty or single-node list
            return;
        }

        Node *evenStart = nullptr, *evenEnd = nullptr;
        Node *oddStart = nullptr, *oddEnd = nullptr;
        Node *current = head;

        while (current != nullptr)
        {
            if (current->data % 2 == 0)
            {
                if (evenStart == nullptr)
                {
                    evenStart = evenEnd = current;
                }
                else
                {
                    evenEnd->next = current;
                    evenEnd = evenEnd->next;
                }
            }
            else
            {
                if (oddStart == nullptr)
                {
                    oddStart = oddEnd = current;
                }
                else
                {
                    oddEnd->next = current;
                    oddEnd = oddEnd->next;
                }
            }
            current = current->next;
        }

        
        if (evenEnd != nullptr)
        {
            evenEnd->next = oddStart;
        }
        if (oddEnd != nullptr)
        {
            oddEnd->next = nullptr;
        }

        head = (evenStart != nullptr) ? evenStart : oddStart;
    }

    // Display the linked list
    void display_List() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "END OF LIST" << endl;
    }
};

int main()
{
    TestLinkList test_list;
    test_list.insert_start(6);
    test_list.insert_start(7);
    test_list.insert_start(1);
    test_list.insert_start(4);
    test_list.insert_start(5);
    test_list.insert_start(10);
    test_list.insert_start(12);
    test_list.insert_start(8);
    test_list.insert_start(15);
    test_list.insert_start(17);

    cout << "Original list: ";
    test_list.display_List();

    test_list.segregateEvenOdd();

    cout << "Segregated linked list: ";
    test_list.display_List();

    return 0;
}
