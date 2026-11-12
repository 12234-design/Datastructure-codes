#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node*children[3];
    Node(int val)
    {
        data=val;
        for(int i=0;i<3;i++)
        {
            children[i]=NULL;
        }
    }
};
void insert(Node*root,int val)
{
    if(!root)return;
    for(int i=0;i<3;i++)
    {
        if(root->children[i]==NULL)
        {
            root->children[i]=new Node(val);
            return;
        }
    }
    for(int i=0;i<3;i++)
    {
        insert(root->children[i],val);
    }
}
void inorder(Node*root)
{
    if(!root)return;
    for(int i=0;i<2;i++)
    {
        inorder(root->children[i]);
    }
    cout<<root->data<<" ";
    inorder(root->children[2]);
}
void preorder(Node*root)
{
    if(!root)return;
    cout<<root->data<<" ";
    for(int i=0;i<2;i++)
    {
        preorder(root->children[i]);
    }
    preorder(root->children[2]);
}