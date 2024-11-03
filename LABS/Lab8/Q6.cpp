#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* prev = NULL;

void inorderTraversal(TreeNode* root) {
    if (!root) return;

    inorderTraversal(root->left);

    if (prev && root->val < prev->val) {
        if (!first) {
            first = prev;
        }
        second = root;
    }
    prev = root;

    inorderTraversal(root->right);
}

void recoverTree(TreeNode* root) {
    inorderTraversal(root);
    if (first && second) {
        swap(first->val, second->val);
    }
}

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "In-order Traversal before recovery: ";
    printInOrder(root);
    cout << endl;

    recoverTree(root);

    cout << "In-order Traversal after recovery: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
