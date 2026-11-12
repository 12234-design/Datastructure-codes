#include <iostream>
using namespace std;

class Node
{
    public:
    int data,height;
    Node*right,*left;
    Node(int val):data(val){right=left=NULL;height=1;}
};
Node* rightrotation(Node*root)
{
    Node*child = root->left;
    Node*childright=child->right;
    child->right=root;
    root->left=childright;

    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));
    return child;
}
Node* leftrotation(Node*root)
{
    Node*child;
    Node*childleft=child->left;
    child->left=root;
    root->right=childleft;

    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));
    return child;
}
int getheight(Node*root)
{
    if(!root)return 0;
    return root->height;
}
int getbalance(Node*root)
{
    if(!root)return 0;
    return getheight(root->left)-getheight(root->right);
}
Node* insert(Node*root,int key)
{
    if(!root)return NULL;
    if(key<root->data)root->left=insert(root->left,key);
    else if(key<root->data)root->right=insert(root->right,key);
    else return root;

    root->height=1+max(getheight(root->left),getheight(root->right));
    int balance=getbalance(root);

    if(balance>1 && key<root->left->data)
    {
        //ll
        return rightrotation(root);
    }
    else if(balance>1 && key>root->left->data)
    {
        //lr
        root->left=leftrotation(root->left);
        return rightrotation(root);
    }
    else if(balance<-1 && key<root->right->data)
    {
        //rl
        root->left=rightrotation(root->right);
        return leftrotation(root);
    }
    else if(balance<-1 && key>root->right->data)
    {
        //rr
        return leftrotation(root);
    }
    else return NULL;
}
Node* deletenode(Node*root,int key)
{
    if(!root)return NULL;
    if(key<root->data)root->left=deletenode(root->left,key);
    else if(key>root->data)root->right=deletenode(root->right,key);
    else
    {
        //node
        if(!root->left && !root->right)
        {
            delete root;return NULL;
        }
        //left child
        else if(root->left && !root->right)
        {
            Node*temp=root->left;
            delete root;
            return temp;
        }
        //right child
        else if(root->right && !root->left)
        {
            Node*temp=root->right;
            delete root;
            return temp;
        }
        //both child
        else
        {
            Node*curr=root->right;
            while(curr->left)
            {
                curr=curr->left;
            }
            root->data=curr->data;
            root->right=deletenode(root->right,curr->data);
        }
    }
    root->height=1+max(getheight(root->left),getheight(root->right));
    int balance=getbalance(root);

    if(balance>1)
    {
        if(getbalance(root->left)>=0)
        {
            //ll
            return rightrotation(root);
        }
        else
        {
            //lr
            root->left=leftrotation(root->left);
            return rightrotation(root);
        }
    }
    else if(balance<-1)
    {
        if(getbalance(root->right)>=0)
        {
            //rr
            return leftrotation(root);
        }
        else
        {
            //rl
            root->right=rightrotation(root->right);
            return leftrotation(root);
        }
    }
    else return root;
}
