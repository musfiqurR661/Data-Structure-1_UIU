#include <bits/stdc++.h>
using namespace std;

// bst tree-> 50,40,20,45,60,55,70;
struct node
{
    int data;
    node *left, *right;
    node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

void Insert(node *root, int key)
{
    node *prev = NULL;
    // node *ptr;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            cout << "Cannot insert " << key << ", already in BST";

            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct node *newNode = new node(key);
    if (key < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *p = new node(50);
    struct node *p1 = new node(40);
    struct node *p2 = new node(20);
    struct node *p3 = new node(45);
    struct node *p4 = new node(60);
    struct node *p5 = new node(55);
    struct node *p6 = new node(70);
    //  tree looks :
    //       50
    //     /    \
    //    40    60
    //   /  \   / \
    //  20  45 55 70

    p->left = p1;
    p1->left = p2;
    p1->right = p3;
    p->right = p4;
    p4->left = p5;
    p4->right = p6;

    // Insert(p,100);
    Insert(p, 10);

    cout << "Binary Search Tree after insertion: ";
    preOrder(p);
    cout << endl;

    return 0;
}

// make node
/*
struct node *makeNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}
*/