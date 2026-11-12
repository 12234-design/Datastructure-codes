#include <iostream>
using namespace std;

class Stack
{
    int n;
    int top;
    int *stack;
    public:
    Stack(int size)
    {
        n=size;
        stack=new int[n];
        top=-1;
    }
    void push(int val)
    {
        if (top==n-1)cout<<"stack is full"<<endl;
        else {top++;
        stack[top]=val;}
    }
    void pop()
    {
        if(top==-1)cout<<"stack already empty"<<endl;
        else{
            top--;
        }
    }
    void printstack()
    {
        if(top==-1)cout<<"stack is empty";
        else
        {
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