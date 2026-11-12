#include<iostream>
using namespace std;

class Stack
{
    int top;
    int n;
    int*stack; 
    public:
    Stack(int size)
    {
        n=size;
        stack=new int[n];
        top=-1;
    }
    void push(int val)
    {
        if(top==n-1){cout<<"stack is full"<<endl;}
        else{
            top=top+1;
            stack[top]=val;
        }
    }
    void pop()
    {
        if(top==-1){cout<<"stack is empty"<<endl;}
        else{
            top=top-1;
        }
    }
    void printstack()
    {
        if(top==-1){cout<<"stack is empty"<<endl;}
        else{
            for(int i=top;i>=0;i--)
            {
                cout<<stack[i]<<endl;
            }
        }
    }
};
int main()
{
    Stack ss(4);
    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(4);
    ss.printstack();
    ss.push(5);
    ss.pop();
    ss.printstack();
}