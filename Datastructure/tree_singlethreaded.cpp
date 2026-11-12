#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    bool rthread;

    Node(int val)
    {
        data = val;
        left = right = NULL;
        rthread = false;
    }
};
Node* leftmost(Node* root)
{
    if(root == NULL)
        return NULL;

    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
void inorder(Node* root)
{
    Node* curr = leftmost(root);
    while(curr != NULL)
    {
        cout << curr->data << " ";
        if(curr->rthread)
        {
            curr = curr->right;
        }
        else
        {
            curr = leftmost(curr->right);
        }
    }
}
Node* insert(Node* root, int val)
{
    if(root == NULL)
        return new Node(val);
    if(val < root->data)
    {
        if(root->left == NULL)
        {
            Node* newnode = new Node(val);
            newnode->right = root;
            newnode->rthread = false;
            root->left = newnode;
        }
        else
        {
            root->left = insert(root->left, val);
        }
    }
    else if(val > root->data)
    {
        if(root->rthread == true)
        {
            root->right = insert(root->right, val);
        }
        else
        {
            Node* newnode = new Node(val);
            newnode->right = root->right;
            newnode->rthread = false;
            root->right = newnode;
            root->rthread = true;
        }
    }
    return root;
}
int main()
{
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "Inorder Traversal: ";
    inorder(root);
    return 0;
}