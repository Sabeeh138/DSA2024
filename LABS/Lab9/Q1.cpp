#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
        return false;
    }
    return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
}

bool isBalanced(TreeNode* root) {
    if (!root) return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

bool isValidAVL(TreeNode* root) {
    return isBST(root, NULL, NULL) && isBalanced(root);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);

    if (isValidAVL(root)) {
        cout << "The tree is a valid AVL tree." << endl;
    } else {
        cout << "The tree is not a valid AVL tree." << endl;
    }

    return 0;
}
