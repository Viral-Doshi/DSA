#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int i=0; i<nums.size(); i++){
            if (lis.size() == 0 || lis[lis.end() - lis.begin() - 1] < nums[i])
                lis.push_back(nums[i]);
            else{
                auto ub = upper_bound(lis.begin(), lis.end(), nums[i]-1);
                lis[ub - lis.begin()] = nums[i];
            }
        }
        return lis.size();
    }
};