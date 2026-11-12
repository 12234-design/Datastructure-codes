#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
int main()
{
    int x,first,second;
    cout<<"enter the root: "<<endl;
    cin>>x;
    queue <Node*>q;
    Node*root = new Node(x);
    q.push(root);
    //build the binary tree
    while(!q.empty())
    {
        Node* temp= q.front();
        q.pop();
        cout<<"enter the left child of "<<temp->data<<" ";
        cin>>first;
        if(first !=-1)
        {
            temp->left=new Node(first);
            q.push(temp->left);
        }
         cout<<"enter the right child of "<<temp->data<<" ";
        cin>>second;
        if(second !=-1)
        {
            temp->right=new Node(second);
            q.push(temp->right);
        }
    }
}