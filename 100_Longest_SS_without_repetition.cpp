#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128);
        int p1 = 0, p2 = 0, res = 0;
        while (p2 < s.length()) {
            // Store in HashMap
            char r = s[p2];
            chars[r]++;
            
            //Increment p1 and decrease window size till found element freq is again 1
            while (chars[r] > 1) {
                char l = s[p1];
                chars[l]--;
                p1++;
            }

            res = max(res, p2 - p1 + 1);
            // Increment p2
            p2++;
        }

        return res;
    }
};