#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> Mat) {
        vector<int> v;
        int i = 0;
        for (i = 0; i < n*n; i++)
            v.push_back(Mat[i/n][i%n]);
        sort(v.begin(),v.end());
        for(i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                Mat[i][j] = v[i*n + j];
            }
        }
        return Mat;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}