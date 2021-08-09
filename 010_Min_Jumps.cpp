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
    int ctr = arr[0], next_ctr= arr[0], steps=1;
    if (n<=1){
        cout << 0;
        exit;
    }
    if (ctr==0){
        cout << -1;
        exit;
    }
    for(int i=1; i<n; i++){
        if (i == n-1)
            break;

        if (i+ arr[i]>next_ctr)
            next_ctr = arr[i] + i;
        ctr--;

        if (ctr == 0){
            steps+=1;
            if (i>= next_ctr){
                steps = -1;
                break;
            }
            ctr = next_ctr-i;
        }
        
    }
    cout << steps;
    return 0;
}