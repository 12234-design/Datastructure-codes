#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *children[3];
    Node(int val)
    {
        data = val;
        for(int i = 0; i < 3; i++)
            children[i] = NULL;
    }
};
void insert(Node *root, int val)
{
    if(root == NULL)
        return;
    for(int i = 0; i < 3; i++)
    {
        if(root->children[i] == NULL)
        {
            root->children[i] = new Node(val);
            return;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        insert(root->children[i], val);
    }
}
void inorder(Node *node)
{
    if(node == NULL)
        return;
    for(int i = 0; i < 2; i++)
        inorder(node->children[i]);
    cout << node->data << " ";
    inorder(node->children[2]);
}
void preorder(Node *node)
{
    if(node == NULL)
        return;
    cout << node->data << " ";
    for(int i = 0; i < 2; i++)
        preorder(node->children[i]);
    preorder(node->children[2]);
}
void postorder(Node *node)
{
    if(node == NULL)
        return;
    for(int i = 0; i < 2; i++)
        postorder(node->children[i]);
    postorder(node->children[2]);
    cout << node->data << " ";
}
int main()
{
    Node *root = new Node(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    return 0;
}