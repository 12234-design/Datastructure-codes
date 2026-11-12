#include <iostream>
using namespace std;

int median (int A[],int l, int r, int k)
{
    int idx = r+l-1;
    int index = rand() % idx;
    int x=0,y=0,z=0;
    int S1[10],S2[1],S3[10];

    for(int i=0;i<r;i++)
    {
        if(A[i]<A[index])
        {
            S1[x]=A[i];
            x++;
        }
        else if(A[i]==A[index])
        {
            S2[y]=A[i];
            y++;
        }
        else
        {
            S3[z]=A[i];
            z++;
        }
    }
    if(x>=k)
    {
        median(S1,0,x-1,k);
    }
    else if((x+y)>=k)
    {
        return A[index];
    }
    else
    {
        median(S3,0,z-1,k-x-y);
    }
}