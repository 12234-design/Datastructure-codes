#include<iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int n;
    int*queue;

    public:
    Queue(int s)
    {
        n=s;
        queue=new int[n];
        front=rear=0;
    }
    bool isempty()
    {
        return(front==rear);
    }
    void enqueue(int val)
    {
        if(rear==n){cout<<"overflow condition"<<endl;}
        else{
            rear++;//if circular queue rear = (rear+1)%s;
            queue[rear]=val;
        }
    }
    void dequeue()
    {
        if(isempty())
        {
            cout<<"underflow condition"<<endl;
        }
        else{
            
            front++;
        }
    }
    int getfront()
    {
        if(isempty())
        {
            cout<<"underflow condition"<<endl;
            return -1;
        }
        else{
            return queue[front];
        }
    }
    int getsize()
    {
        return (rear-front);
    }
    void printqueue()
    {
        for (int i=front;i<rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Queue q(3);
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.printqueue();
    q.enqueue(400);
    q.dequeue();    
    q.printqueue();
}