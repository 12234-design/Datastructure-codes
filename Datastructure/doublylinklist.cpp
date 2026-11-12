#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node (int val):data(val){next=prev=NULL;}  
};
class List
{
    Node* head;
    Node *tail;
    public:
    List()
    {
        head=tail=NULL;
    }
    void pushfront(int val)
    {
        Node* newnode= new Node(val);
        if(head == NULL)
        {
            head=tail=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        
    }
    void pushback(int val)
    {
        Node *newnode=new Node(val);
        if (head == NULL)
        {
            head=tail=newnode;
        }
        else{
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
    }
    void popfront()
    {
        Node*temp=head;
        head=head->next;
        if (head!=NULL)
        {
        head->prev=NULL;
        }
        temp->next=NULL;        
        delete temp;

    }
    void popback()
    {
        Node *temp=tail;
        tail=tail->prev;
        if(tail!=NULL)
        {
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
        
    }
    void printll()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    List ll;
    ll.pushfront(1);
    ll.pushfront(2);
    ll.pushfront(3);
    ll.popback();
    ll.popfront();
    ll.printll();

}