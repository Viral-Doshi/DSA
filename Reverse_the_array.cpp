#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <int> arr;
    int n,temp;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    int k = arr.size()-1;
    for (int i=0; i<arr.size()/2; i++){
        temp = arr[i];
        arr[i] = arr[k-i];
        arr[k-i] = temp;
    }
    for (int i=0; i<=k; i++) cout << arr[i] << " ";

    return 0;
}