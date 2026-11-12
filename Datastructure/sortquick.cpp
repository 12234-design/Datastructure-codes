// partition(arr,lb,ub)
// {
//     int pivot=arr[0];
//     int start=lb;
//     int end=ub;
//     while(start<end)
//     {
//         while(a[start]<=pivot)
//         {
//             start++
//         }
//         while(a[end]>pivot)
//         {
//             end--;
//         }
//         if(start<end)
//         {
//             swap(a[start],a[end])
//         }
//     }
//     swap(a[lb],a[end]);
//     return end;
// }
// quicksort(arr,ub,lb)
// {
//     if(lb<ub)
//     {
//         int loc = partision(arr,ub,lb); 
//         quicksort(arr,lb,loc-1);
//         quicksort(arr,loc+1,ub);
//     }
// }