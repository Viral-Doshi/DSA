#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,temp;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> temp;
        arr[i] = temp;
    }
    sort(arr,arr+n);
    int max_ele, min_ele, min_ht_diff = arr[n-1]-arr[0];
    for(int i = 0; i < n; i++){
        if (arr[i+1]-k < 0)
            continue;
        max_ele = max(arr[i]+k, arr[n-1]-k);
        min_ele = min(arr[0]+k, arr[i+1]-k);
        min_ht_diff = min(min_ht_diff, max_ele-min_ele);
    }
    cout << min_ht_diff;
    return 0;
}