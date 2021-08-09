#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& hist) {
        stack<int> s;
        int n = hist.size(), max_area = 0, tp, area_with_top, i = 0;
        while (i < n){
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);
            else{
                tp = s.top();
                s.pop();
                area_with_top = hist[tp] * (s.empty() ? i : (i-1) - s.top());
                if (max_area < area_with_top) max_area = area_with_top;
            }
        }
        while (s.empty() == false){
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? n : n - s.top() - 1);
            if (max_area < area_with_top) max_area = area_with_top;
        }

        return max_area;
    }
};