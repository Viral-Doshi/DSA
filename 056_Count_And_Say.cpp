#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n){
        if(n == 1) return "1";
        if(n == 2) return "11";
          
        string str = "11";        
        for(int i = 3; i <= n; i++){
            str += '$';
            int len = str.length(), cnt = 1;
            string tmp = "";
             
            for(int j = 1; j < len; j++){
                if(str[j] != str[j - 1]){
                        tmp += cnt + '0';
                        tmp += str[j - 1];
                        cnt = 1;
                    }
                else
                    cnt++;
            }
            str = tmp;  
         }
         
        return str;
    }
};

// Reccursive
class Solution {
public:
    string prev, res;
    string& countAndSay(int n) {
        if(n == 1){
            res = "1";
            return res;
        }
        prev = countAndSay(n-1);
        const int N = prev.length();
        int count,j;
        res = "";
        for(int i=0;i<N;){
            count = 0;
            for(j=i;prev[i]==prev[j];j++){
                count++;
            }
            res += to_string(count) + prev[i];
            i=j;
        }
        
        return res;
    }
};