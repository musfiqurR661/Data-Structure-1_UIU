#include <iostream>
using namespace std;

// Define the structure of a binary search tree (BST) node
struct node {
    int data;
    node *left, *right;
    node(int k) {
        data = k;
        left = right = NULL;
    }
};

// Function to insert a new key into the BST
void Insert(node *root, int key) {
    node *prev = NULL; // Pointer to keep track of the previous node
    while (root != NULL) {
        prev = root; // Update the previous node before moving down
        if (key == root->data) {
            cout << "Cannot insert " << key << ", already in BST";
            return;
        } else if (key < root->data) {
            root = root->left; // Move to the left subtree
        } else {
            root = root->right; // Move to the right subtree
        }
    }
    // Create a new node with the given key
    node *newNode = new node(key);
    if (key < prev->data) {
        prev->left = newNode; // Insert as the left child
    } else if (key > prev->data) {
        prev->right = newNode; // Insert as the right child
    } else {
        // Handle the case where key == prev->data (if needed)
    }
}

int main() {
        // Create nodes for the initial BST
    node *p = new node(50);
    node *p1 = new node(40);
    node *p2 = new node(20);
    node *p3 = new node(45);  // Different data value from the one below
    node *p4 = new node(60);
    node *p5 = new node(55);
    node *p6 = new node(70);

    // Build the initial BST structure
    p->left = p1;
    p1->left = p2;
    p1->right = p3;
    p->right = p4;
    p4->left = p5;
    p4->right = p6;

    // Insert a new key (55) into the BST
    Insert(p, 55);

    // Print the data of a specific node in the BST
   // cout << p->right->right->data; // This should print 70
    cout << p->right->right->right->data;


    // Free allocated memory for nodes to prevent memory leaks
    delete p;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;

    return 0;

}
