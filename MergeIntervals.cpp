#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> a = {intervals[0]};
        vector<int> temp;
        for(int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= a[cnt][1] && intervals[i][0] >= a[cnt][0]){
                temp = {a[cnt][0],max(a[cnt][1],intervals[i][1])};
                a[cnt] = temp;
                continue;
            }
            temp = {intervals[i][0],intervals[i][1]};
            a.push_back(temp);
            cnt++;
            
        }
        return a;
    }
};