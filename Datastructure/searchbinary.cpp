// start = 0
// end = n-1
// while (start <= end)
// {
//     mid = (start + end) / 2;
//     if (arr[mid] == key) cout<<got it<<endl; break;
//     else if (arr[mid] < key) start = mid + 1;
//     else end = mid -1;
// }
#include <iostream>
using namespace std;

int BinarySearch(int arr[],int n, int key)
{
    int start =0;
    int end = n-1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key) {cout<<"got it"<<endl; return mid; break;}
        else if (arr[mid] < key) start = mid + 1;
        else end = mid -1;
    }
    return -1;
}
int main()
{
    int arr[100];
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    cout<<"enter elements ";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"enter the key";
    cin>>key;

    cout<<BinarySearch(arr,n,key);
    return 0;
}