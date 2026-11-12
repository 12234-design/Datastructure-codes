#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*right,*left;
    bool rthread,lthread;
    Node(int val):data(val){right=left=NULL;rthread=lthread=false;}
};

Node*leftmost(Node*root)
{
    if(root==NULL)return;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

void inorder(Node*root)
{
    Node*curr=leftmost(root);
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        if(curr->rthread==false)curr=curr->right;
        else curr=leftmost(curr->right);
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
            newnode->rthread = true;

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
            Node* newnode = new Node(val);

            newnode->right = root->right;
            newnode->rthread = true;

            root->right = newnode;
            root->rthread = false;
        }
        else
        {
            root->right = insert(root->right, val);
        }
    }

    return root;
}

int main()
{
    Node *root = NULL;

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