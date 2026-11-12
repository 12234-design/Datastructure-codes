#include <iostream>
using namespace std;

void maxHeapify(int A[], int i, int n)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;
    // Check left child
    if (left <= n && A[left] > A[i])
        largest = left;
    else
        largest = i;
    // Check right child
    if (right <= n && A[right] > A[largest])
        largest = right;
    if (largest != i)
    {
        swap(A[i],A[largest]);
        maxHeapify(A, largest, n);
    }
}

void buildMaxHeap(int A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(A, i, n);
    }
}

void maxHeapInsert(int A[], int &n, int value)
{
    n++;
    int i = n;
    A[i] = value;
    while (i > 1/*if root has parent or not*/ && A[i] > A[i / 2]/*greater than parent or not*/)
    {
        swap(A[i],A[i / 2]);
        i = i / 2;//parent is at i/2
    }
}
//DELETION
int maxHeapDelete(int A[], int &n)
{
    if (n == 0)
    {
        cout << "Max Heap is empty!" << endl;
        return -1;
    }
    int deleted = A[1];
    // Replace root with last element
    A[1] = A[n];
    n--;
    maxHeapify(A, 1, n);
    return deleted;
}

void heapsort(int A[],int n)
{
    buildMaxHeap(A,n);
    for(int i=n;i>=2;i--)
    {
        swap(A[1],A[i]);
        maxHeapify(A,1,i-1);
    }
}

void minHeapify(int A[], int i, int n)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest;
    // Check left child
    if (left <= n && A[left] < A[i])
        smallest = left;
    else
        smallest = i;
    // Check right child
    if (right <= n && A[right] < A[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(A[i],A[smallest]);
        minHeapify(A, smallest, n);
    }
}

void buildMinHeap(int A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        minHeapify(A, i, n);
    }
}

void minHeapInsert(int A[], int &n, int value)
{
    n++;
    int i = n;
    A[i] = value;
    while (i > 1 && A[i] < A[i / 2])
    {
        swap(A[i],A[i / 2]);
        i = i / 2;
    }
}
//DELETION
int minHeapDelete(int A[], int &n)
{
    if (n == 0)
    {
        cout << "Min Heap is empty!" << endl;
        return -1;
    }
    int deleted = A[1];
    // Replace root with last element
    A[1] = A[n];
    n--;
    minHeapify(A, 1, n);
    return deleted;
}

void display(int A[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int maximum(int A[], int n)
{
    if (n == 0)return -1;
    else return A[1];
}
int extractMax(int A[], int &n)
{
    if (n == 0)return -1;
    int maximum = A[1];
    A[1] = A[n];
    n--;
    maxHeapify(A, 1, n);
    return maximum;
}
//key of element at index i to k
void increaseKey(int A[], int n, int i, int k)
{
    if (i < 1 || i > n)return;
    if (k < A[i])
    {
        cout << "New key is smaller than current key!" << endl;
        return;
    }
    A[i] = k;
    while (i > 1 && A[i] > A[i / 2])
    {
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

void maxPriorityQueue()
{
    int P[100];
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i];
    }

    buildMaxHeap(P, n);
    cout << "\nMax Priority Queue: ";
    display(P, n);

    int value;
    cout << "\nEnter value to INSERT: ";
    cin >> value;
    maxHeapInsert(P, n, value);
    cout << "After INSERT: ";
    display(P, n);

    cout << "\nMAXIMUM: ";
    cout << maximum(P, n) << endl;

    int index, key;
    cout << "\nEnter index for INCREASE-KEY: ";
    cin >> index;
    cout << "Enter new key: ";
    cin >> key;
    increaseKey(P, n, index, key);
    cout << "After INCREASE-KEY: ";
    display(P, n);

    int extracted = extractMax(P, n);
    cout << "After EXTRACT-MAX: ";
    display(P, n);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[100];
    cout << "Enter elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    cout << "\nOriginal array: ";
    display(A, n);

        int B[100];

    for (int i = 1; i <= n; i++)
    {
        B[i] = A[i];
    }

    heapsort(B, n);

    cout << "Array after Heap Sort: ";
    display(B, n);

    buildMaxHeap(A, n);
    cout << "Max Heap: ";
    display(A, n);

    int value;
    cout << "\nEnter value to insert in Max Heap: ";
    cin >> value;
    maxHeapInsert(A, n, value);
    cout << "Max Heap after insertion: ";
    display(A, n);
 
    int deletedMax = maxHeapDelete(A, n);
    cout << "Max Heap after deletion: ";
    display(A, n);


    buildMinHeap(A, n);
    cout << "\nMin Heap: ";
    display(A, n);

    cout << "\nEnter value to insert in Min Heap: ";
    cin >> value;
    minHeapInsert(A, n, value);
    cout << "Min Heap after insertion: ";
    display(A, n);

    int deletedMin = minHeapDelete(A, n);
    cout << "Min Heap after deletion: ";
    display(A, n);

    
    maxPriorityQueue();


    return 0;
}