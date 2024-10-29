#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxProfitPathHelper(TreeNode* node, int currentSum, int& maxProfit) {
    if (!node) return 0;

    currentSum += node->val;

    // If the node is a leaf, update maxProfit if current path sum is higher
    if (!node->left && !node->right) {
        maxProfit = max(maxProfit, currentSum);
    }

    // Recursive calls for left and right subtrees
    if (node->left) maxProfitPathHelper(node->left, currentSum, maxProfit);
    if (node->right) maxProfitPathHelper(node->right, currentSum, maxProfit);

    return maxProfit;
}

int maxProfitPath(TreeNode* root) {
    if (!root) return 0;
    int maxProfit = INT_MIN;
    maxProfitPathHelper(root, 0, maxProfit);
    return maxProfit;
}

int main() {
  

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int maxProfit = maxProfitPath(root);
    cout << "Maximum Profit Path Sum: " << maxProfit << endl;

    return 0;
}
