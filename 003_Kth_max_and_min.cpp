// https://www.cdn.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
// https://www.cdn.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/

// M1 --> Normal Sort O(Nlog(N)) O(1)
// M2 --> Min Heap O(N + klog(N)) O(1)
// **M3 --> QuickSelect + Random Expected: O(N) Space O(1)
// **M4 --> Median of Medians: Worst Case: O(N) Space: O(log(N))


#include<bits/stdc++.h>
using namespace std;

void swap(int* x, int* y);

class MinHeap{
    int* arrptr;
    int capacity;
    int heap_size;

    public:
        MinHeap(int A[], int size);
        int GetMin() {return arrptr[0];}
        void Heapify( int i);
        int ExtractMin();
        int parent(int i) {return (i-1)/2;}
        int left(int i) {return 2*i;}
        int right(int i) {return 2*i+1;}

};
MinHeap::MinHeap(int A[], int size){
    heap_size = size;
    arrptr = A;
    for (int i = (heap_size-1)/2; i >=0; i--)
        Heapify(i);
}
int MinHeap::ExtractMin(){
    if (heap_size <= 0)
        return INT_MAX;
    swap(arrptr[0],arrptr[heap_size-1]);
    heap_size-=1;
    Heapify(0);
    return arrptr[heap_size-1];
}
void MinHeap::Heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest;
    if (l < heap_size && arrptr[l] < arrptr[i])
        smallest = l;
    else  smallest = i;
    if (r < heap_size && arrptr[r] < arrptr[smallest])
        smallest = r;
    if (smallest != i){
        swap(&arrptr[smallest],&arrptr[i]);
        Heapify(smallest);
    }
}
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int kthSmallest_M1(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}
int kthSmallest_M2(int arr[],int n,int k){
    MinHeap Heap(arr,n);
    while(k--)
        Heap.ExtractMin();
    return Heap.GetMin();
}
int kthSmallest_M3(int arr[],int n,int k){

    return k;
}

int main(){
    int n,k;
    cin >> n;
    int *arr;
    arr = new int[n];
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    cin >> k;
    cout << "K'th smallest element is " << kthSmallest_M2(arr, n, k-1);
    return 0;
}