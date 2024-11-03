#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int x) : val(x), left(NULL), right(NULL), height(1) {}
};

// Helper function to get the height of a node
int getHeight(TreeNode* node) {
    return node ? node->height : 0;
}

// Helper function to calculate the balance factor of a node
int getBalance(TreeNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Function to perform a right rotation
TreeNode* rightRotate(TreeNode* y, int &rotationCount) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    rotationCount++;
    return x;
}

// Function to perform a left rotation
TreeNode* leftRotate(TreeNode* x, int &rotationCount) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    rotationCount++;
    return y;
}

// Function to insert a node and perform AVL rotations
TreeNode* insert(TreeNode* node, int key, int &rotationCount) {
    if (!node) return new TreeNode(key);

    if (key < node->val)
        node->left = insert(node->left, key, rotationCount);
    else if (key > node->val)
        node->right = insert(node->right, key, rotationCount);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->val)
        return rightRotate(node, rotationCount);

    if (balance < -1 && key > node->right->val)
        return leftRotate(node, rotationCount);

    if (balance > 1 && key > node->left->val) {
        node->left = leftRotate(node->left, rotationCount);
        return rightRotate(node, rotationCount);
    }

    if (balance < -1 && key < node->right->val) {
        node->right = rightRotate(node->right, rotationCount);
        return leftRotate(node, rotationCount);
    }

    return node;
}

int main() {
    TreeNode* root = NULL;
    int rotationCount = 0;
    int keys[] = {10, 20, 30, 25, 5, 15};

    for (int key : keys) {
        root = insert(root, key, rotationCount);
    }

    cout << "Total rotations performed: " << rotationCount << endl;
    return 0;
}
