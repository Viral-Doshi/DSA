#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums){
    int n = nums.size();
    int i = n-1, j = n-1;
    if (n == 1)
        return;
    for(; i > 0; i--){
        if (nums[i] > nums[i-1])
            break;  
    }
    if (i==0){
        sort(nums.begin(), nums.end());
        return;
    }
    for(; j >= i; j --){
        if (nums[i-1] < nums[j])
            break;
    }
    swap(nums[i-1],nums[j]);
    sort(nums.begin()+i,nums.end());
    
}

int main(){
    int n,temp;
    cin >> n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    nextPermutation(nums);
    for(int i=0; i<n; i++)
        cout << nums[i] << " ";
    return 0;
}