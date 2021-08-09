#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        for (int i=1; i<n; i++)
            if (prices[i] > prices[i-1])
                profit += prices[i] - prices[i - 1];
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