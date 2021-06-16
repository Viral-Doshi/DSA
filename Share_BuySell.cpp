#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int buy = prices[0] ,profit = 0;
    for(int i=1; i<prices.size(); i++){
        buy = min(prices[i],buy);
        profit = max(prices[i]-buy, profit);                
    }
    return profit;
}
int main(){
    int n,temp;
    cin >> n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    temp = maxProfit(nums);
    cout << temp;
    return 0;
}