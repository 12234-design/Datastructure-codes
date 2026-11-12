#include <iostream>
using namespace std;

class Queue
{
    int rear;
    int front;
    int n;
    int * queue;
    public:
    Queue(int size)
    {
        n=size;
        queue=new int[n];
        rear=front=0;
    }
    bool isempty()
    {
        return(rear==front);
    }
    void push(int val)
    {
        if(rear==n){cout<<"overflow condition"<<endl;}
        else
        {
            
            queue[rear]=val;rear++;
        }
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"underflow condition"<<endl;
        }
        else front++;
    }
    int getfront()
    {
        if(isempty())
        {
            cout<<"underflow condition"<<endl;
            return -1;
        }
        else return queue[front];
    }
    void printqueue()
    {
        if(isempty())
        {
            cout<<"underflow condition"<<endl;
        }
        else
        {
            for(int i=front;i<rear;i++)
            {
                cout<<queue[i]<<" ";
            }
        }
    }
};
int main()
{
    
    Queue q(3);
    q.push(100);
    q.push(200);
    q.push(300);
    q.printqueue();
    q.push(400);
    q.pop();    
    q.printqueue();
}