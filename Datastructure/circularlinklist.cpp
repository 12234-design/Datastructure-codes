#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node*next;
    Node(int val):data(val){next=NULL;}
};
class List
{
    Node*head;
    Node*tail;
    public:
    List()
    {
        head=tail=NULL;
    }
    void insertathead(int val)
    {
        Node *newnode= new Node(val);
        if(head==NULL)
        {
            head=tail=newnode;
            tail->next=head;
        }
        else{
            newnode->next=head;
            head=newnode;
            tail->next=head;
        }
    }
    void insertattail(int val)
    {
        Node* newnode=new Node(val);
        if(tail==NULL)
        {
            head=tail=newnode;
            tail->next=head;
        }
        else{
            newnode->next=head;
            tail->next=newnode;
            tail=newnode;

        }
    }
    void deleteathead()
    {
        if (head==NULL)return;
        else if (head==tail)
        {
            delete head;
            tail=head=NULL;
        }
        else{
        Node*temp=head;
        head=head->next;
        tail->next=head;
        temp->next=NULL;
        delete temp;
        }
    }
    void deleteattail()
    {
        if(tail==NULL)return;
        else if(tail==head){
            delete tail;
            tail=head=NULL;
        }
        else{
            Node *temp=tail;    
            Node *prev=head;
            while(prev->next!=tail)
            {
                prev=prev->next;
            }
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }
    void printll()
    {
        if(head==NULL)return;
        cout<<head->data<<" ";
        Node*temp=head->next;

        while(temp!=head)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};
int main()
{
    List ll;
    ll.insertattail(1);
    ll.insertattail(2);
    ll.insertattail(3);
    ll.deleteattail();
    
    ll.printll();

}