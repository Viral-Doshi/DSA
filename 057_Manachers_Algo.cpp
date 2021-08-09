#include <bits/stdc++.h>
using namespace std;

void FormatString(string& s){
    s = '$' + s + '@';
    int n = s.size();
    for (int i = 0; i < s.size()-1; i++){
        s = s.substr(0,i+1) + "#" + s.substr(i+1,s.size()-i-1);
        i++;
    }
}

int ManachersAlgo(string& s){
    int n = s.length();
    if (n==0) return 0;
    vector<int> larr (n,0);
    int c = 0, r = 0;
    cout << n << " " << s << '\n';
    //for (int i = 1; i < n; i++) cout << "Hi";
    for (int i = 1; i < n; i++){
        int l_mirror = 2*c - i;
        if (i<r)
            larr[i] = min(r-i, larr[l_mirror]);
        while(s[i + (larr[i] + 1)] == s[i - (larr[i] + 1)]){
            larr[i]++;
        }
        if (i + larr[i] > r){
            c = i;
            r = i + larr[i];
        }
    }
    return *max_element(larr.begin(), larr.end());

}

int main(){
    string s;
    cin >> s;
    FormatString(s);
    //cout << s;
    cout << ManachersAlgo(s);
    return 0;
}