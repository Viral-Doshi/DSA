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
    int start=0,curr_max=INT_MIN;
    for (int i=0; i<n; i++){
        start += arr[i];
        if (curr_max < start){
            curr_max = start;
        }
        if (start<0)
            start=0;
    }
    cout << curr_max;
    return 0;
}