/*
doing this with the built it queue library 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    vector<int> keys;
    vector<Node*> children;
    bool isLeaf;

    Node(bool leaf) {
        isLeaf = leaf;
    }

    void insertKey(int key) {
        keys.push_back(key);
        sort(keys.begin(), keys.end());
    }
};

void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = q.front();
            q.pop();

            
            for (int key : currentNode->keys) {
                cout << key << " ";
            }
            cout << "  "; // Separate nodes at the same level

            
            for (Node* child : currentNode->children) {
                q.push(child);
            }
        }
        cout << endl; 
    }
}

int main() {
    Node* root = new Node(false);
    root->insertKey(20);
    root->insertKey(38);

    root->children.push_back(new Node(true));
    root->children[0]->insertKey(10);
    root->children[0]->insertKey(15);

    root->children.push_back(new Node(true));
    root->children[1]->insertKey(25);
    root->children[1]->insertKey(30);

    root->children.push_back(new Node(true));
    root->children[2]->insertKey(40);
    root->children[2]->insertKey(50);

    cout << "Level-order traversal of the 2-3 tree:" << endl;
    levelOrderTraversal(root);

    return 0;
}
