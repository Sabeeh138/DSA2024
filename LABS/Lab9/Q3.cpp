#include <iostream>
#include <vector>
#include <algorithm>
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

void collectElements(Node* root, vector<int>& elements) {
    if (root == nullptr) return;
    for (int key : root->keys) {
        elements.push_back(key);
    }
    for (Node* child : root->children) {
        collectElements(child, elements);
    }
}

Node* build23Tree(const vector<int>& elements) {
    if (elements.empty()) return nullptr;

    Node* root = new Node(false);
    root->keys.push_back(elements[elements.size() / 2]);

    Node* leftChild = new Node(true);
    Node* rightChild = new Node(true);

    for (size_t i = 0; i < elements.size() / 2; i++) {
        leftChild->keys.push_back(elements[i]);
    }

    for (size_t i = elements.size() / 2 + 1; i < elements.size(); i++) {
        rightChild->keys.push_back(elements[i]);
    }

    root->children.push_back(leftChild);
    root->children.push_back(rightChild);

    return root;
}

Node* merge23Trees(Node* tree1, Node* tree2) {
    vector<int> elements;

    collectElements(tree1, elements);
    collectElements(tree2, elements);

    sort(elements.begin(), elements.end());

    return build23Tree(elements);
}

void printTree(Node* root, int level = 0) {
    if (root == nullptr) return;
    for (int i = 0; i < level; i++) cout << "  ";
    for (int key : root->keys) {
        cout << key << " ";
    }
    cout << endl;
    for (Node* child : root->children) {
        printTree(child, level + 1);
    }
}

int main() {
    Node* tree1 = new Node(false);
    tree1->insertKey(10);
    tree1->insertKey(20);
    tree1->children.push_back(new Node(true));
    tree1->children[0]->insertKey(5);
    tree1->children.push_back(new Node(true));
    tree1->children[1]->insertKey(15);
    tree1->children.push_back(new Node(true));
    tree1->children[2]->insertKey(25);

    Node* tree2 = new Node(false);
    tree2->insertKey(35);
    tree2->insertKey(40);
    tree2->children.push_back(new Node(true));
    tree2->children[0]->insertKey(30);
    tree2->children.push_back(new Node(true));
    tree2->children[1]->insertKey(38);
    tree2->children.push_back(new Node(true));
    tree2->children[2]->insertKey(50);

    Node* mergedTree = merge23Trees(tree1, tree2);

    cout << "Merged 2-3 Tree:" << endl;
    printTree(mergedTree);

    return 0;
}
