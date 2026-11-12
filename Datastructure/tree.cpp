#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
    Node(int val):data(val){left=right=NULL;}
};
Node* Binarytree()
{
    int x;
    cin >>x;
    if(x==-1)return NULL;
    Node*temp=new Node(x);
    cout<<"enter left child of "<<x<<" ";
    temp->left=Binarytree();
    cout<<"enter right child of "<<x<<" ";
    temp->right=Binarytree();
    return temp;
}
void preorder(Node*root)
{
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node*root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node*root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelorder(Node*root){
    queue<Node*>q;
    q.push(root);
    Node*temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
}
void preorderiterative(Node*root)
{
    stack<Node*>s;
    s.push(root);
    Node*temp;
    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right)s.push(temp->right);
        if(temp->left)s.push(temp->left);
    }
}
void inorderiterative(Node*root)
{
    stack<Node*>s;
    Node*temp=root;
    while(temp!=NULL || !s.empty())
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
void postorderiterative(Node*root)
{
    if(root==NULL)return;
    stack<Node*>s1,s2;
    s1.push(root);
    Node*temp;
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)s1.push(temp->left);
        if(temp->right)s1.push(temp->right);
    }
    while(!s2.empty())
    {
        temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
}
int total(Node*root,int count)
{
    if(root==NULL)return 0;
    count++;
    total(root->left,count);
    total(root->right,count);
}
int summ(Node*root,int sum)
{
    if(root==NULL)return 0;
    sum+=root->data;
    summ(root->left,sum);
    summ(root->right,sum);
}
int height(Node*root)
{
    if(root==NULL)return 0;
    return(1+max(height(root->left),height(root->right)));
}