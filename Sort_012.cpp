// Maintain 3 pointers and 4 sections;  0-low:0  low-mid:1  mid-high:unknown  nigh-n-1:2

#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int n, a;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a;
        arr[i] = a;
    }
    int low=0, mid=0, high=n-1;
    while(mid < high){
        if (arr[mid] == 0){
            swap(arr[mid],arr[low]);
            low+=1;
            mid+=1;
        }
        else if (arr[mid] == 1){
            mid+=1;
        }
        else{
            swap(arr[mid],arr[high]);
            high-=1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}