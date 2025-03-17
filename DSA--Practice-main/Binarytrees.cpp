#include <iostream>
using namespace std;

// Node structure for the Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

    // Recursive helper function to insert into the binary tree (not level-wise)
    Node* insertRecursively(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRecursively(node->left, value);
        } else {
            node->right = insertRecursively(node->right, value);
        }
        return node;
    }

    // Helper for in-order traversal
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Helper for pre-order traversal
    void preorderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // Helper for post-order traversal
    void postorderTraversal(Node* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

public:
    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert data recursively
    void insert(int value) {
        root = insertRecursively(root, value);
    }

    // In-order traversal (Left, Root, Right)
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    // Pre-order traversal (Root, Left, Right)
    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    // Post-order traversal (Left, Right, Root)
    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }
};

// Main function for demonstration
int main() {
    BinaryTree tree;

    // Insert nodes recursively without using a queue
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Traversals
    cout << "In-order traversal: ";
    tree.inorder();  // Output: 20 30 40 50 60 70 80

    cout << "Pre-order traversal: ";
    tree.preorder(); // Output: 50 30 20 40 70 60 80

    cout << "Post-order traversal: ";
    tree.postorder(); // Output: 20 40 30 60 80 70 50

    return 0;
}
