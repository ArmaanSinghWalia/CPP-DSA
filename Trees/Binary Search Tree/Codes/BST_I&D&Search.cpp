#include <iostream>
using namespace std;

/*
 * Node Structure for Binary Search Tree (BST)
 */
class Node {
public:
    int value;      // Value of the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor
    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

/*
 * Inorder Traversal: Left -> Root -> Right
 * Prints the BST in sorted order.
 */
void InOrder(Node* Root) {
    if (Root == nullptr) return;
    InOrder(Root->left);
    cout << Root->value << " ";
    InOrder(Root->right);
}

/*
 * Insert a value into BST
 * Smaller values go left, equal or larger values go right.
 */
Node* Insert(Node* Root, int newval) {

    // Base Case: Empty tree or leaf reached
    if (Root == nullptr) {
        return new Node(newval);
    }

    // Recursive insertion
    if (newval < Root->value) {
        Root->left = Insert(Root->left, newval);
    }
    else {
        Root->right = Insert(Root->right, newval);
    }

    return Root;
}

/*
 * Search for a key in BST
 * Returns pointer to node if found, nullptr if not.
 */
Node* Search(Node* Root, int key) {
    if (Root == nullptr || Root->value == key) {
        return Root;
    }

    if (key < Root->value) {
        return Search(Root->left, key);
    }
    else {
        return Search(Root->right, key);
    }
}

/*
 * Helper function to search and print result
 */
void PrintAndSearch(Node* Root, int key) {
    Node* Result = Search(Root, key);
    if (Result != nullptr) {
        cout << key << " found in the tree." << endl;
    }
    else {
        cout << key << " not found in the tree." << endl;
    }
}

/*
 * Find node with minimum value in BST (leftmost node)
 */
Node* MinElement(Node* Root) {
    while (Root && Root->left) {
        Root = Root->left;
    }
    return Root;
}

/*
 * Delete a node from BST
 * Handles all cases:
 * 1) Leaf Node
 * 2) One Child
 * 3) Two Children
 */
Node* DeleteNode(Node* Root, int key) {

    if (Root == nullptr) return Root;  // Empty tree

    // Traverse to correct subtree
    if (key < Root->value) {
        Root->left = DeleteNode(Root->left, key);
    }
    else if (key > Root->value) {
        Root->right = DeleteNode(Root->right, key);
    }
    else {
        // Node found

        // Case 1: Leaf Node
        if (Root->left == nullptr && Root->right == nullptr) {
            delete Root;
            return nullptr;
        }

        // Case 2: One Child Only
        else if (Root->right == nullptr) {      // Left child only
            Node* temp = Root->left;
            delete Root;
            return temp;
        }
        else if (Root->left == nullptr) {    // Right child only
            Node* temp = Root->right;
            delete Root;
            return temp;
        }

        // Case 3: Two Children
        Node* temp = MinElement(Root->right);  // Find inorder successor
        Root->value = temp->value;             // Copy successor's value
        Root->right = DeleteNode(Root->right, temp->value); // Delete successor
    }

    return Root;
}

/*
 * Main function: Demonstrates BST operations
 */
int main() {

    Node* root = nullptr;

    // Insert elements
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 70);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 60);
    root = Insert(root, 80);

    cout << "Inorder Traversal of BST --> ";
    InOrder(root);
    cout << endl << endl;

    // Search examples
    cout << "Search Examples:" << endl;
    PrintAndSearch(root, 40);
    PrintAndSearch(root, 100);
    cout << endl;

    // Original tree
    cout << "Original tree (InOrder) --> ";
    InOrder(root);
    cout << endl;

    // Delete nodes
    cout << "\nDeleting nodes 20, 50, 70..." << endl;
    root = DeleteNode(root, 20);
    root = DeleteNode(root, 50);
    root = DeleteNode(root, 70);

    // Updated tree
    cout << "\nUpdated tree (InOrder) --> ";
    InOrder(root);
    cout << endl;

    return 0;
}
