#include <iostream>
using namespace std;
// bst tree-> 50,40,20,45,60,55,70;
struct node
{
    int key;
    node *left, *right;
    node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

node *Search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->key == key)
    {
        return root; // 45 ptr node*
    }
    else if (key < root->key)
    {
        return Search(root->left, key);
    }
    else
    {
        return Search(root->right, key);
    }
}

int main()
{
    /*node *root = new node(50);
    root->left = new node(40);
    root->left->left = new node(20);
    root->left->right = new node(45);
    root->right = new node(60);
    root->right->left = new node(55);
    root->right->right = new node(70);

    //  cout<<Search(root,49)->key<<endl;
    */

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

    // Searching in a BST

    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;
    if (Search(p, key) == NULL)
        printf("%d not found\n", key);
    else
        printf("%d found\n", key);
    return 0;
}