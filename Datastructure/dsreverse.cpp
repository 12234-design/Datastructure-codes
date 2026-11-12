#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val):data(val){}
};
class List
{
    Node *head;
    Node *tail;
    public:
    List()
    {
        head=tail=NULL;
    }
    void reverse()
    {
        Node*current=head;
        Node*prev=NULL;
        Node*next=NULL;
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
        
    }
    void push_front(int val)
        {
            Node *newnode = new Node(val);
            if (head == NULL)
            {
                head=tail=newnode; 
                return;
            }
            else
            {
                newnode-> next= head;
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
            tail->next=newnode;
        }
    }
    void PrintLL()
        {
            Node *temp=head;
            while(temp!= NULL)
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
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.PrintLL();
    ll.reverse();
    ll.PrintLL();

}