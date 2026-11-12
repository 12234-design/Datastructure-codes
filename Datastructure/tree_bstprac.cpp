#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node*left,*right;
    Node(int val):data(val){left=right=NULL;}
};
Node* insert(Node*root,int val)
{
    if(!root)return new Node(val);
    else if(val<root->data){root->left=insert(root->left,val);}
    else root->right=insert(root->right,val);
    return root;
}
void inorder(Node*root)
{
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool search(Node*root,int key)
{
    if(!root)return 0;

    if(key==root->data)return 1;
    else if(key<root->data){return search(root->left,key);}
    else return search(root->right,key);
}
Node*deletenode(Node*root,int target)
{
    if(!root)return NULL;
    if(target<root->data){root->left=deletenode(root->left,target);return root;}
    else if(target>root->data){root->right=deletenode(root->right,target);return root;}
    else
    {
        //node
        if(!root->left&&!root->right)
        {delete root;return NULL;}
        //left
        else if(root->left&&!root->right)
        {
            Node * temp= root->left;
            delete root;
            return temp;
        }
        //right
        else if(root->right && !root->left)
        {
            Node*temp= root->right;
            delete root;
            return temp;
        }
        //both
        else
        {
            Node*child=root->left;
            Node * parent=root;
            while (child->right)
            {
                parent=child;
                child = child->right;
            }
            if(root!=parent)
            {
                parent->right=child->left;
                child->left=root->left;
                child->right=root->right;
                delete root;
                return child;
            }
            else
            {
                child->right=root->right;
                delete root;
                return child;
            }
        }
    }

}