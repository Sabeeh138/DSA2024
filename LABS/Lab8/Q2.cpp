#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);
    vector<int> levelNodes;

    while (!currentLevel.empty()) {
        TreeNode* node = currentLevel.top();
        currentLevel.pop();
        levelNodes.push_back(node->val);

        if (leftToRight) {
            if (node->left) nextLevel.push(node->left);
            if (node->right) nextLevel.push(node->right);
        } else {
            if (node->right) nextLevel.push(node->right);
            if (node->left) nextLevel.push(node->left);
        }

        if (currentLevel.empty()) {
            result.push_back(levelNodes);
            levelNodes.clear();
            swap(currentLevel, nextLevel);
            leftToRight = !leftToRight;
        }
    }

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> zigzagOrder = zigzagLevelOrder(root);
    cout << "Zigzag Order Traversal:" << endl;
    for (const auto& level : zigzagOrder) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
