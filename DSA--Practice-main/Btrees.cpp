#include <iostream>
using namespace std;

const int M = 3; // Order of the B-tree (minimum degree)

// B-tree node structure
struct BTreeNode {
    int *keys;               // Array of keys in the node
    BTreeNode **children;    // Array of child pointers
    int numKeys;             // Number of keys in the node
    bool leaf;               // True if node is a leaf, false otherwise

    // Constructor to initialize the node
    BTreeNode(bool isLeaf, int maxKeys) {
        leaf = isLeaf;
        keys = new int[maxKeys];
        children = new BTreeNode*[maxKeys + 1];
        numKeys = 0;
    }
};

// B-tree class
class BTree {
private:
    BTreeNode *root;

    // Recursive function to search for a key in the subtree rooted with the given node
    BTreeNode* search(BTreeNode* node, int key) {
        int i = 0;

        // Find the first key greater than or equal to the key
        while (i < node->numKeys && key > node->keys[i]) {
            i++;
        }

        // If the key is found
        if (i < node->numKeys && key == node->keys[i]) {
            return node;
        }

        // If this node is a leaf, then the key is not present
        if (node->leaf) {
            return nullptr;
        }

        // Otherwise, search in the appropriate child
        return search(node->children[i], key);
    }

    // Recursive function to insert a non-full node
    void insertNonFull(BTreeNode* node, int key) {
        int i = node->numKeys - 1;

        // If the node is a leaf, insert the key in the correct position
        if (node->leaf) {
            while (i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->numKeys++;
        } else {
            // Find the child to recurse into
            while (i >= 0 && node->keys[i] > key) {
                i--;
            }
            i++;

            // If the child is full, split it
            if (node->children[i]->numKeys == M - 1) {
                splitChild(node, i);
                if (key > node->keys[i]) {
                    i++;
                }
            }
            insertNonFull(node->children[i], key);
        }
    }

    // Recursive function to split a child node
    void splitChild(BTreeNode* parent, int index) {
        BTreeNode* fullChild = parent->children[index];
        BTreeNode* newChild = new BTreeNode(fullChild->leaf, M - 1);

        // Move the last (M-1)/2 keys to the new child
        newChild->numKeys = M / 2;
        for (int j = 0; j < M / 2; j++) {
            newChild->keys[j] = fullChild->keys[j + M / 2 + 1];
        }

        // If the child is not a leaf, move the last (M/2) children pointers
        if (!fullChild->leaf) {
            for (int j = 0; j < M / 2; j++) {
                newChild->children[j] = fullChild->children[j + M / 2 + 1];
            }
        }

        // Decrease the number of keys in the full child
        fullChild->numKeys = M / 2;

        // Shift the parent's children and keys to make space for the new child
        for (int j = parent->numKeys; j > index; j--) {
            parent->children[j + 1] = parent->children[j];
        }

        parent->children[index + 1] = newChild;

        // Shift the parent's keys to make space for the middle key of the child
        for (int j = parent->numKeys - 1; j >= index; j--) {
            parent->keys[j + 1] = parent->keys[j];
        }

        // Move the middle key from the full child to the parent
        parent->keys[index] = fullChild->keys[M / 2];
        parent->numKeys++;
    }

    // Recursive function to handle root split if needed
    void handleRootSplit() {
        if (root->numKeys == M - 1) {
            BTreeNode* newRoot = new BTreeNode(false, M - 1);
            newRoot->children[0] = root;
            splitChild(newRoot, 0);
            root = newRoot;
        }
    }

    // Recursive function for inorder traversal
    void inorderTraversal(BTreeNode* node) {
        int i = 0;
        while (i < node->numKeys) {
            if (!node->leaf) {
                inorderTraversal(node->children[i]);
            }
            cout << node->keys[i] << " ";
            i++;
        }

        if (!node->leaf) {
            inorderTraversal(node->children[i]);
        }
    }

public:
    BTree() {
        root = new BTreeNode(true, M - 1); // Create an empty root node
    }

    // Public insert function
    void insert(int key) {
        handleRootSplit();
        insertNonFull(root, key);
    }

    // Public search function
    bool search(int key) {
        BTreeNode* result = search(root, key);
        return result != nullptr;
    }

    // Public inorder traversal function
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BTree tree;

    // Insert keys into the B-tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    // Print the B-tree in inorder
    cout << "Inorder traversal of the B-tree: ";
    tree.inorder();

    // Search for a key
    int keyToSearch = 12;
    if (tree.search(keyToSearch)) {
        cout << "Key " << keyToSearch << " found in the B-tree." << endl;
    } else {
        cout << "Key " << keyToSearch << " not found in the B-tree." << endl;
    }

    return 0;
}
