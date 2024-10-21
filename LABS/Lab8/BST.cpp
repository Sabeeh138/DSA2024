#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
    friend class BinarySearchTree;
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    Node* Insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = Insert(root->left, data);
        }
        else if (data > root->data) {
            root->right = Insert(root->right, data);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void insert(int data) { 
        root = Insert(root, data);
    }
};

int main() {
    BinarySearchTree b;

    
    b.insert(10);
    b.insert(20);
    b.insert(8);
    b.insert(12);
    b.insert(16);
    b.insert(25);
    b.insert(32);
    b.insert(6);
    b.insert(35);

    cout << "InOrder: ";
    b.inorder(b.root); 
    cout << endl;

    return 0;
}
