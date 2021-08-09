#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,bool> map;
    for(int i=0; i<n; i++){
        if (map.find(a1[i]) == map.end())
            map[a1[i]] = true;
    }
    for(int i=0; i<m; i++){
        if (map.find(a2[i]) == map.end())
            return "No";
    }
    return "Yes";
}