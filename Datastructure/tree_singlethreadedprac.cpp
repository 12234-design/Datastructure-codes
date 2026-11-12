#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;
    bool rthread;
    Node(int val) : data(val)
    {
        right = left = NULL;
        rthread = false;
    }
};
Node *leftmost(Node *root)
{
    if (!root)
        return NULL;
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
void inorder(Node *root)
{
    Node *curr = leftmost(root);
    while (curr != NULL)
    {
        cout << curr->data << " ";
        if (curr->rthread)
        {
            curr = curr->right;
        }
        else
        {
            curr = leftmost(curr->right);
        }
    }
}
Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
    {
        if (root->left == NULL)
        {
            Node *newnode = new Node(val);
            newnode->right = root;
            newnode->rthread = false;
            root->left=newnode;
        }
        else
        {
            root->left=insert(root->left,val);
        }
    }
    else if(val>root->data)
    {
        if(root->rthread = true)
        {
            root->right=insert(root->right,val);
        }
        else
        {
            Node * newnode= new Node(val);
            newnode->right=root->right;
            newnode->rthread=false;
            root->right=newnode;
            root->rthread=true;
        }
    }
}