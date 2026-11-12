// int position(int arr[],int lb,int ub)
// {
//     int pivot = arr[0];
//     int start=lb;
//     int end = ub;
//     while(start<end)
//     {
//         while(arr[start]<=pivot)start++;
//         while(arr[end]>pivot)end--;
//         if(start<end)
//         {
//             swap(arr[start],arr[end]);
//         }
//     }
//     swap(arr[lb],arr[end]);
//     return end;
// }
// quicksort(int arr[],int ub,int lb)
// {
//     if(ub>lb)
//     {
//         int loc=position(arr,lb,ub);
//         quicksort(arr,loc-1,lb);
//         quicksort(arr,ub,loc+1);
//     }
// }