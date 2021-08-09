// Used the same approach as median in a row wise sorted matrix.

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
      return 0;
}

int kthSmallest(int matrix[MAX][MAX], int n, int k){
        int minimum = INT_MAX, maximum = INT_MIN;
        minimum = matrix[0][0];
        maximum = matrix[n-1][n-1];
        int de = k, count = 0, mid;
        while(minimum < maximum){
            mid = minimum + (maximum-minimum)/2;
            count = 0;
            for(int i = 0; i < n; i++)
                count += upper_bound(matrix[i], matrix[i] + n, mid)- matrix[i];
            if (count < de)
                minimum = mid+1;
            else
                maximum = mid;
        }
        return minimum;
        
    }