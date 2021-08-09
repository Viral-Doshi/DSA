#include<bits/stdc++.h>
using namespace std;

tuple<int,int> MinMax(vector<int> arr, int low, int high){
    tuple<int,int> mmr, mml, minmax;
    int tempmin, tempmax, mid;
    if (high == low){
        minmax = make_tuple(arr[low],arr[low]);
        return minmax;
    }
    else if (high == low+1){
        if (arr[low] > arr[high])
            minmax = make_tuple(arr[high],arr[low]);
        else
            minmax = make_tuple(arr[low],arr[high]);
        return minmax;
    }
    else{
        mid = (low + high)/2;
        mml = MinMax(arr, low, mid);
        mmr = MinMax(arr, mid+1, high);

        tempmin = (get<0>(mml) < get<0>(mmr)) ? get<0>(mml) : get<0>(mmr);
        tempmax = (get<1>(mml) > get<1>(mmr)) ? get<1>(mml) : get<1>(mmr);
        minmax = make_tuple(tempmin,tempmax);
        return minmax;  
    }
}
int main(){
    int n,temp;
    vector<int> a;
    cin >> n;
    while(n--){
        cin >> temp;
        a.push_back(temp);
    }
    tuple <int,int> ans;
    ans = MinMax(a,0,a.size()-1);
    cout << get<0>(ans) << " " << get<1>(ans);
    return 0;
}