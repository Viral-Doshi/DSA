#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    string CheckPal(int l1, int r1, string &s){
        int i1 = l1, j1 = r1;
        bool flag = false;
        while(i1 >= 0 and j1 < s.length() and s[i1] == s[j1]){
            flag = true;
            i1 --;
            j1 ++;
        }
        if (flag){
            return s.substr(i1+1,j1-i1-1);
        }
        return s.substr(j1-1,1);
    }
    
    string longestPalindrome(string s) {
        int l1 = 0, r1 = 0;
        string curr_str, max_str;
        while (l1 < s.length() and r1 < s.length()){
            curr_str = CheckPal(l1, r1, s);
            max_str = curr_str.length() > max_str.length() ? curr_str : max_str;
            r1++;
            curr_str = CheckPal(l1, r1, s);
            max_str = curr_str.length() > max_str.length() ? curr_str : max_str;
            l1++;
            
        }
        return max_str;
    }
};