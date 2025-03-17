#include <iostream>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int val){
        left = right = NULL;
        data = val;
    }
};

int height(Node* root){
    if(root == NULL){
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

int countnodes(Node* root){
    if(root == NULL){
        return -1;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return new Node(data);
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if(lheight<rheight){
        root->left = insert(root->left, data);
    }
    else if(rheight<lheight){
        root->right = insert(root->right,data);
    }
    return root;
}

Node* getrightmostnode(Node* root){
    if(root->right==NULL){
        return root;
    }
    return getrightmostnode(root->right);
}

Node* deleterightmostnode(Node* root, Node* parent){
    if(root->right){
        return deleterightmostnode(root->right, root);
    }
    if(parent){
        if(parent->right){
            parent->right = NULL;
        }
        else {
            parent->left = NULL;
        }
    }
    delete root;
    return parent;
}

Node* deletenode(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deletenode(root->left, key);
    } else if (key > root->data) {
        root->right = deletenode(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL) {
            // Case 1: Leaf node
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            // Case 2: Only right child
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            // Case 2: Only left child
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // Case 3: Two children
            Node* rightmost = getrightmostnode(root->left);
            root->data = rightmost->data;  // Copy the value
            root->left = deletenode(root->left, rightmost->data); // Delete the duplicate
        }
    }
    return root;
}

// Helper function to print in-order traversal
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deletenode(root, 50); // Delete node with key 50

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}