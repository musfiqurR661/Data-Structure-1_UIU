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
struct node *inPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *DeleteNode(node *root, int value)
{
    struct node *inPre;

    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // 1st search for the node to be deleted
    if (value < root->data)
    {
        root->left = DeleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = DeleteNode(root->right, value);
    }

    // deletion when the node is found
    else
    {
        inPre = inPredecessor(root); // recursively call 50, 40, 60..
        root->data = inPre->data;
        root->left = DeleteNode(root->left, inPre->data); // delete this value from this root
    }
    return root;
}

int main()
{
    // struct node *p = new node (50);
    // struct node *p1 = new node(40);
    // struct node *p2 = new node(20); 
    // struct node *p3 = new node(45);
    // struct node *p4 = new node(60);
    // struct node *p5 = new node(55);
    // struct node *p6 = new node(70);
    // //  tree looks :
    //       50/p
    //     /     \
    //    40/p1    60/p4
    //   /    \       / \
    //  20/p2 45/p3 55/p5 70/p6
//    p->left = p1;
//     p1->left = p2;
//     p1->right = p3;
//     p->right = p4;
//     p4->left = p5;
//     p4->right = p6;
    //------------------------------------------//
    struct node *p = new node(5);
    struct node *p1 = new node(2);
    struct node *p2 = new node(15);
    struct node *p3 = new node(35);
    struct node *p4 = new node(30);
    struct node *p5 = new node(50);
   // struct node *p6 = new node(70);
    // new class  5,2,15,35,30,50
    //      5
    //     / \
    //    2   15
    //        / \
    //          35
    //          / \
    //         30 50
    p->left = p1;
    p1->left = NULL;
    p1->right = NULL;
    p->right = p2;
    p2->right = p3;
    p3->left = p4;
    p3->right=p5;

    // Insert(p,100);
    inOrder(p);
    printf("\n");
    preOrder(p);
    printf("\n");
    postOrder(p);
    DeleteNode(p,5);
    printf("\n");
    printf("\nNew root is %d |\n" , p->data);
    inOrder(p);
    printf("\n");
    preOrder(p);
    printf("\n");
    postOrder(p);



    return 0;
}