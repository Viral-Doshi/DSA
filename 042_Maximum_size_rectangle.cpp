#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/
int maxHist(int hist[], int m){
    int i = 0, curr_area,max_area=0, top_idx;
    stack<int> s;
    while (i < m){
        if (s.empty() or hist[s.top()] < hist[i]){
            s.push(i);
            i++;
        }
        else{
            top_idx = s.top();
            s.pop();
            if (s.empty())
                curr_area = hist[top_idx] * i;
            else
                curr_area = hist[top_idx] * (i - 1 - s.top());
            max_area = max(max_area,curr_area);
        }
    }
    while(!s.empty()){
        top_idx = s.top();
        s.pop();
        if (s.empty())
            curr_area = hist[top_idx] * i;
        else
            curr_area = hist[top_idx] * (i - 1 - s.top());
        max_area = max(max_area,curr_area);
    }
    return max_area;
}

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int result = maxHist(M[0], m);
        for (int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if (M[i][j])
                    M[i][j] += M[i-1][j];
            }
            result = max(result, maxHist(M[i],m));
        }
        return result;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}