#include <iostream>
using namespace std;

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

node *Insert(node *root, int key)
{
    if (root == NULL)
        return new node(key);

    if (key < root->key)
        root->left = Insert(root->left, key);
    else
        root->right = Insert(root->right, key);

    return root;
}
node *FindMin(node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

node *Transplant(node *root, node *u, node *v)
{
    if (u->left == NULL)
        root = v;
    else if (u == u->left->right)
    {
        u->left = v;
        v->right = u;
    }
    else
    {
        u->left = v;
        v->right = u;
    }
    return root;
}

node *DeleteNode(node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = DeleteNode(root->left, key);
    else if (key > root->key)
        root->right = DeleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *inSucc = FindMin(root->right);
        root->key = inSucc->key;
        root->right = DeleteNode(root->right, inSucc->key);
    }
    return root;
}
int height(node *root)
{
    if (root == NULL)
        return -1; // Height of an empty tree is -1
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

bool find(node *root, int key)
{
    if (root == NULL)
        return false;

    if (key == root->key)
        return true;
    else if (key < root->key)
        return find(root->left, key);
    else
        return find(root->right, key);
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

// void printTree(node *root, int level = 0)
// {
//     if (root != NULL)
//     {
//         printTree(root->right, level + 1);
//         for (int i = 0; i < level; i++)
//             cout << "    ";
//         cout << root->key << endl;
//         printTree(root->left, level + 1);
//     }
// }
void printTree(node *root)
{
    if (root != NULL)
    {

        printTree(root->left);
        cout << root->key << " ";
        printTree(root->right);
    }
}

int main()
{
    node *root = NULL;

    while (true)
    {
        cout << "Choose an operation:" << endl;

        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Print In-order Traversal" << endl;
        cout << "5. Print Pre-order Traversal" << endl;
        cout << "6. Print Post-order Traversal" << endl;
        cout << "7. After Delete " << endl;
        cout << "8. Height " << endl;
        cout << "9. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int key;
            cout << "Enter the key to insert: ";
            cin >> key;
            root = Insert(root, key);
            //  cout << "Tree after insertion:" << endl;
            // printTree(root);
        }

        else if (choice == 2)
        {
            int key;
            cout << "Enter the key to delete: ";
            cin >> key;
            if (find(root, key))
            {
                root = DeleteNode(root, key);
                cout << key << " deleted" << endl;
            }
            else
            {
                cout << key << " not found" << endl;
            }
        }

        else if (choice == 3)
        {
            int key;
            cout << "Enter the key to search: ";
            cin >> key;
            if (find(root, key))
                cout << key << " found" << endl;
            else
                cout << key << " not found" << endl;
        }

        else if (choice == 4)
        {
            cout << "In-order Traversal: ";
            inOrder(root);
            cout << endl;
        }
        else if (choice == 5)
        {
            cout << "Pre-order Traversal: ";
            preOrder(root);
            cout << endl;
        }
        else if (choice == 6)
        {
            cout << "Post-order Traversal: ";
            postOrder(root);
            cout << endl;
        }
        else if (choice == 7)
        {
            cout << "Tree after operation:" << endl;
            printTree(root);
            cout << endl;
        }
        else if (choice == 8)
        {
            int treeHeight = height(root);
            cout << "Height of the tree: " << treeHeight << endl;
        }
        else if (choice == 9)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }

    return 0;
}
