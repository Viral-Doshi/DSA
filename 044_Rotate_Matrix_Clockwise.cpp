#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp, n = matrix.size();
        for(int j = 0; j <= (n+1)/2; j++){
            for (int i = j; i < n-j-1; i++){
                temp = matrix[j][i];
                matrix[j][i] = matrix[n-1-i][j];
                matrix[n-1-i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
    }
};