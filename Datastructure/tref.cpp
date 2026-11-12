#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int val): data(val){left=right=NULL;}
};
Node * binarytree()
{
    int x;
    cin>>x;
    Node*temp=new Node(x);
    cout<<"enter left child of "<<x<<endl;
    temp->left=binarytree();
    cout<<"enter right child of "<<x<<endl;
    temp->right=binarytree();
    return temp;
}
void levelorder(Node* root)
{
    queue <Node*> q;
    q.push(root);
    Node*temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
void preorder(Node*root)
{
    stack <Node*> s;
    s.push(root);
    Node*temp;
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
}
void inorder(Node*root)
{
    stack <Node*>s;
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
void postorder(Node*root)
{
    if(root==NULL)return;
    stack <Node*> s1,s2;
    Node*temp;
    s1.push(root);
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)s1.push(temp->left);
        if(temp->right)s1.push(temp->right);
    }
    while (!s2.empty())
    {
        temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }

}
int countnodes(Node*root,int count)
{
    if(!root)return 0;
    count++;
    countnodes(root->left,count);
    countnodes(root->right,count);
}
int summ(Node*root,int sum)
{
    if(!root)return 0;   
    sum=sum+root->data;
    summ(root->left,sum);
    summ(root->right,sum);
}
int height(Node*root)
{
    if (!root)return 0;
    return 1+max(height(root->left),height(root->right));
}