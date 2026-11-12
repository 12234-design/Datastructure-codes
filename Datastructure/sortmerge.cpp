// merge(arr,lb,mid,ub)
// {
//     i=lb;
//     j=mid+1;
//     k=lb;
//     while(i<=mid && j<=ub)
//     {
//         if(a[i]<= a[j])
//         {
//             b[k]=a[i];
//             i++;
//         }
//         else
//         {
//             b[k]=a[j];
//             j++;
//         }
//         k++
//     }
//     if(i>mid)
//     {
//         while(j<=ub)
//         {
//             b[k]=a[j];
//             j++;
//             k++;
//         }
//     }
//     else{
//         while (i<=mid)
//         {
//             b[k]=a[i];
//             i++;
//             k++;
//         }
//     }
//     for(int k=lb;k<=ub;k++)
//     {
//         a[k]=b[k];
//     }
// }
// mergesort(arr,lb,ub)
// {
//     if (lb<ub)
//     {
//         mid = (ub+lb)/2;
//         mergesort(arr,lb,mid)
//         mergesort(arr,mid+1,ub)
//         merge(arr,lb,mid,ub)
//     }
// }