// int maximum(int A[], int n)
// {
//     if (n == 0)return -1;
//     else return A[1];
// }
// int extractMax(int A[], int &n)
// {
//     if (n == 0)return -1;
//     int maximum = A[1];
//     A[1] = A[n];
//     n--;
//     maxHeapify(A, 1, n);
//     return maximum;
// }
// //key of element at index i to k
// void increaseKey(int A[], int n, int i, int k)
// {
//     if (i < 1 || i > n)return;
//     if (k < A[i])
//     {
//         cout << "New key is smaller than current key!" << endl;
//         return;
//     }
//     A[i] = k;
//     while (i > 1 && A[i] > A[i / 2])
//     {
//         swap(A[i], A[i / 2]);
//         i = i / 2;
//     }
// }

// void maxPriorityQueue()
// {
//     int P[100];
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;
//     cout << "Enter elements: ";
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> P[i];
//     }

//     buildMaxHeap(P, n);
//     cout << "\nMax Priority Queue: ";
//     display(P, n);

//     int value;
//     cout << "\nEnter value to INSERT: ";
//     cin >> value;
//     maxHeapInsert(P, n, value);
//     cout << "After INSERT: ";
//     display(P, n);

//     cout << "\nMAXIMUM: ";
//     cout << maximum(P, n) << endl;

//     int index, key;
//     cout << "\nEnter index for INCREASE-KEY: ";
//     cin >> index;
//     cout << "Enter new key: ";
//     cin >> key;
//     increaseKey(P, n, index, key);
//     cout << "After INCREASE-KEY: ";
//     display(P, n);

//     int extracted = extractMax(P, n);
//     cout << "After EXTRACT-MAX: ";
//     display(P, n);
// }