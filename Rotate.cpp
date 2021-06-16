#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,temp;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> temp;
        arr[i] = temp;
    }
    for(int i=n-1; i>=1; i--)
        swap(arr[i],arr[i-1]);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}