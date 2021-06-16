#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,temp;
    cin >> n;
    int* nums = new int[n];
    for(int i=0; i<n; i++){
        cin >> temp;
        nums[i] = temp;
    }

    int t = nums[0];
    int h = nums[0];
    while(true){
        t = nums[t];
        h = nums[nums[h]];
        if (t == h)
            break;
    }
    t = nums[0];
    while (t!=h){
        t = nums[t];
        h = nums[h];
    }
    cout << h;
    return 0;
}