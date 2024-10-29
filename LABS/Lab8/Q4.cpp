#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two trees are identical
bool isIdentical(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isIdentical(t1->left, t2->left) &&
           isIdentical(t1->right, t2->right);
}

// Function to check if T2 is a subtree of T1
bool isSubtree(TreeNode* T1, TreeNode* T2) {
    if (!T2) return true;  // An empty tree is always a subtree
    if (!T1) return false; // T2 is not empty, but T1 is empty

    if (isIdentical(T1, T2)) return true;
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

int main() {
    // Constructing tree T1
    TreeNode* T1 = new TreeNode(1);
    T1->left = new TreeNode(2);
    T1->right = new TreeNode(3);
    T1->left->left = new TreeNode(4);
    T1->left->right = new TreeNode(5);
    T1->right->left = new TreeNode(6);
    T1->right->right = new TreeNode(7);

    // Constructing tree T2
    TreeNode* T2 = new TreeNode(3);
    T2->left = new TreeNode(6);
    T2->right = new TreeNode(7);

    if (isSubtree(T1, T2)) {
        cout << "T2 is a subtree of T1" << endl;
    } else {
        cout << "T2 is NOT a subtree of T1" << endl;
    }

    return 0;
}
