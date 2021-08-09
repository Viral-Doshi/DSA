#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lis_ending_here(int till_here, int a[]){
        if (till_here == 0) return 1;
        int ans = 1;
        for(int i = till_here-1; i >= 0; i--){
            if (a[i] < a[till_here]) ans = max(ans, 1+ lis_ending_here(i, a));
        }
        return ans;
    }
    int lis(int n, int a[]){
        int final_ans = 1;
        for (int i=0; i<n; i++) final_ans = max(final_ans, lis_ending_here(i, a));
        return final_ans;
    }
};