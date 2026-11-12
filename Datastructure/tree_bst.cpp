#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int val):data(val){left=right=NULL;}
};
void inorder(Node * root)
{
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* insert(Node*root,int val)
{
    if(!root)
    {
        Node * temp = new Node(val);
        return temp;
    }
    if(val<root->data) root->left = insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}
bool search(Node *root, int target)
{
    if(!root)return 0;
    if(root->data == target)return 1;
    if(root->data<target)return(search(root->left,target));
    else return(search(root->right,target));
}
Node *deleteNode(Node * root, int target)
{
    if(!root)return NULL;
    if(root->data>target){root->left = deleteNode(root->left,target);return root;}
    else if(root->data<target){root->right = deleteNode(root->right,target);return root;}
    else{
        //leaf node
        if(!root->left && !root->right){delete root;return NULL;}
        //1child
        else if(!root->right)//left child exists
        {
            Node*temp=root->left;
            delete root;
            return temp;
        }
        else if(!root->left)//right child exists
        {
            Node*temp=root->right;
            delete root;
            return temp;
        }
        //2child
        else
        {
            //left side ka maxm(rightmost)
            Node*child=root->left;
            Node* parent = root;
            
            while(child->right)
            {
                parent=child;
                child=child->right;
            }
            if(root!=parent)
            {
                parent->right=child->left;//parent ko bolo child ke left ko point kre(parent ko, naki root ko)
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
int main()
{
    int arr[]={3,7,4,1,6,8};
    Node*root;
    for(int i=0;i<6;i++)
    {
        root=insert(root,arr[i]);
    }
    inorder(root);
}