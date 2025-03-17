#include <iostream>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int data;

    Node(int val){
        left = right = NULL;
        data = val;
    }
};

Node* insert(Node* root,int key){
    if(root == NULL){
        return new Node(key);
    }
    
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if (key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}

void inordertraversal(Node* root){
    if(root!=NULL){
        inordertraversal(root->left);
        cout<<root->data<<" ";
        inordertraversal(root->right);
    }
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    else if ( key < root->data){
        return search(root->left, key);
    }
    else return search(root->right, key);   
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int calcheight(Node* root){
    if(root == NULL){
        return -1;
    }
    int lheight = calcheight(root->left);
    int rheight = calcheight(root->right);

    return max(lheight, rheight) + 1;
}


int main(){
    Node* root = NULL;
    
    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // Inorder traversal
    cout << "Inorder traversal of the BST: ";
    inordertraversal(root);
    cout << endl;
    int height = calcheight(root);
    cout<<"height of bst is"<<height<<endl;
    
    return 0;
}
