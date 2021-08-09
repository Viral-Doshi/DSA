#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,temp,k;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> temp;
        arr[i] = temp;
    }
    unordered_map <int,int> m;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (m.find(arr[i]) == m.end())
            m[arr[i]] = 1;
        else
            m[arr[i]] += 1;
    }
    for (int i = 0; i < n; i++) {
        cnt += m[k - arr[i]];
        if (k - arr[i] == arr[i])
            cnt--;
    }
    cout << cnt/2;
}