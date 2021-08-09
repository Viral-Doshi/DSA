#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int minimum = INT_MAX, maximum = INT_MIN;
        for (int i=0; i<r; i++){
            minimum = min(minimum,matrix[i][0]);
            maximum = max(maximum,matrix[i][c-1]);
        }
        int de = (r*c + 1)/2, count = 0, mid;
        while(minimum < maximum){
            mid = minimum + (maximum-minimum)/2;
            count = 0;
            for(int i = 0; i < r; i++)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid)- matrix[i].begin();
            if (count < de)
                minimum = mid+1;
            else
                maximum = mid;
        }
        return minimum;
        
    }
};

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}