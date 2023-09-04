#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int value = 0;
    struct Node* parent = NULL;
    struct Node* left = NULL;
    struct Node* right = NULL;
} node;
void transplant(node* toBeReplaced, node* replacedBy) // Replace a node by another node
{
    replacedBy->parent = toBeReplaced->parent;

    if(toBeReplaced->parent == NULL) return;

    if(toBeReplaced->parent->left == toBeReplaced)
        toBeReplaced->parent->left == replacedBy;
    else
        toBeReplaced->parent->right == replacedBy;

    return;
}

node* search(node* root, int key)
{
    if(root == NULL || root->value == key)
        return root;
    if(root->value > key)
        return search(root->left, key);
    return search(root->right, key);
}

node* minimum(node* root)
{
    if(root->left == NULL)
        return root;
    return minimum(root->left);
}

node* maximum(node* root)
{
    if(root->right == NULL)
        return root;
    return maximum(root->right);
}

node* successor(node* keyNode)
{
    if(keyNode->right != NULL)
        return minimum(keyNode->right);

    node* keyNodeParent = keyNode->parent;

    while(keyNodeParent != NULL && keyNodeParent->right == keyNode)
    {
        keyNode = keyNodeParent;
        keyNodeParent = keyNodeParent->parent;
    }
    return keyNodeParent;
}

node* predecessor(node* keyNode)
{
    if(keyNode->left != NULL)
        return maximum(keyNode->left);

    node* keyNodeParent = keyNode->parent;

    while(keyNodeParent != NULL && keyNodeParent->left == keyNode)
    {
        keyNode = keyNodeParent;
        keyNodeParent = keyNodeParent->parent;
    }
    return keyNodeParent;
}

node* insert(node* root, int key)
{
    node* newNode = (node*) malloc(sizeof(node));
    if(!newNode)
        cout << "Heap overflow" << endl;
    newNode->value = key;
    if(root == NULL)
        return newNode;
    node* traveller = root;
    while(traveller != NULL)
    {
        if(traveller->left == NULL && key < traveller->value)
        {
            traveller->left = newNode;
            newNode->parent = traveller;
        }
        else if(traveller->right == NULL && key >= traveller->value)
        {
            traveller->right = newNode;
            newNode->parent = traveller;
        }
        if(key < traveller->value)
            traveller = traveller->left;
        else
            traveller = traveller->right;
    }
    return root;
}

node* Delete(node* root, node* keyNode)
{
    if(keyNode->left == NULL)
    {
        if(keyNode->parent == NULL)
            root = keyNode->right;
        else
            transplant(keyNode, keyNode->right);
    }
    else if(keyNode->right == NULL)
    {
        if(keyNode->parent == NULL)
            root = keyNode->left;
        else
            transplant(keyNode, keyNode->left);
    }
    else
    {
        node* minimumNode = minimum(keyNode->right);

        if(keyNode->parent == NULL)
            root = minimumNode;
        if(minimumNode == keyNode->right)
        {
            transplant(keyNode, minimumNode);
            minimumNode->left = keyNode->left;
            minimumNode->left->parent = minimumNode;
        }
        else
        {
            transplant(minimumNode, minimumNode->right);
            minimumNode->left = keyNode->left;
            minimumNode->left->parent = minimumNode;
            minimumNode->right = keyNode->right;
            minimumNode->right->parent = minimumNode;
        }
    }
    free(keyNode);
    return root;
}

​void 
printInOrder(node* root)
{
    enum Flag{
    gotoRight,
    gotoleft
    };
    Flag flag = gotoleft;

    stack<node*> stk;
    stk.push(root);
    while(stk.empty())
    {
        if(root->left == NULL)
        {​
        }

        stk.push(root)​
            flag = gotoRight;
        else if(root->right == NULL)
            flag = gotoLeft;
        if(flag == gotoLeft)
​
    }
}
​
int main()
{
    node* root = NULL;
    insert(root, 100);
    for(int i=10; i<200; i+=10)
        insert(root, i);
    printInOrder(root);
}