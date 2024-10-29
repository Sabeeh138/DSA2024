#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


string serialize(TreeNode* root) {
    if (!root) return "# ";
    return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
}

// Helper function for deserialization
TreeNode* deserializeHelper(istringstream& iss) {
    string val;
    iss >> val;
    if (val == "#") return NULL;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeHelper(iss);
    node->right = deserializeHelper(iss);
    return node;
}

// Deserialize the tree from a string
TreeNode* deserialize(const string& data) {
    istringstream iss(data);
    return deserializeHelper(iss);
}

// Utility function to print the tree (inorder traversal)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serializedTree = serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserialize the tree
    TreeNode* deserializedRoot = deserialize(serializedTree);
    cout << "Inorder Traversal of Deserialized Tree: ";
    inorder(deserializedRoot);
    cout << endl;

    return 0;
}
