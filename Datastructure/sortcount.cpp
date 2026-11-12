// countsort(int arr[],int n)
// {
//     int max=arr[0];
//     int b[n];
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]>max)max=arr[i];
//     }
//     int count[max+1]={0};
//     for(int i=0;i<n;i++)
//     {
//         count[arr[i]]++;
//     }
//     for(int i=1;i<=max;i++)
//     {
//         count[i]=count[i]+count[i-1];
//     }
//     for(int i=n-1;i>=0;i--)
//     {
//         b[--count[arr[i]]]=arr[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         arr[i]=b[i];
//     }
// }