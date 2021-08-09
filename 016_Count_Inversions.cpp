#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void Merge(int arr[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int* left = new int[n1];
    int* right = new int[n2];

    for(int i =0; i<n1; i++)
        left[i] = arr[l+i];
    for(int j=0; j<n2; j++)
        right[j] = arr[m+1+j];

    int i=0, j=0, k=l, rel_pos;
    while (i < n1 && j < n2){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            rel_pos = i - (k-l);
            rel_pos = (rel_pos > 0 ? rel_pos:0);
            cnt += rel_pos;
            i++;
        }
        else{
            arr[k] = right[j];
            rel_pos = (n1+j) - (k-l);
            rel_pos = (rel_pos > 0 ? rel_pos:0);
            cnt += rel_pos;
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r){
    if (l >= r)
        return;
    int m = (l+r)/2;
    MergeSort(arr, l, m);
    MergeSort(arr, m+1, r);
    Merge(arr,l,m,r);
}

int main(){
    int n,temp;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> temp;
        arr[i] = temp;
    }
    MergeSort(arr,0,n-1);
    cout << cnt;
    return 0;
}

