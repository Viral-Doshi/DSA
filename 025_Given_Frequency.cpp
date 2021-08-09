#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, temp, k;
    cin >> n >> k;
    int* arr = new int[n];
    unordered_map<int,int> freq;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr[i] = temp;
        if (freq.find(arr[i]) == freq.end())
            freq[arr[i]] = 1;
        else
            freq[arr[i]] ++;
    }
    int need = n/k;
    vector<int> a;
    for(auto const& x: freq){
        if (x.second > need)
            a.push_back(x.first);
    }
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }    
    
    return 0;
}