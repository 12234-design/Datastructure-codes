void countsort(int arr[],int n,int pos)
{
    int m=10;
    int count[m]={0};
    int b[n];
    for(int i=0;i<n;i++)
    {
        count[(arr[i]/pos)%10]++;
    }
    for (int i=1;i<m;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        b[--count[(arr[i]/pos)%10]] = arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=b[i];
    }
}
void radix(int arr[],int n)
{
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)max=arr[i];
    }
    for (int pos=1;max/pos>0;pos*=10)
    {
        countsort(arr,n,pos);
    }
}
