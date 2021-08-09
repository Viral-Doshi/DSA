#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
	    int idx=m,ans=-1;
        for(int i = 0; i < m; i ++){
            if (arr[0][i] == 1){
                idx = i;
                ans = 0;
                break;
            }
        }
        //cout << idx;
        if (idx == 0)
            return 0;
        for (int j = 1; j < n; j++){
            if (arr[j][idx-1] == 1){
                ans = j;
                idx -= 1;
                while(arr[j][idx-1] == 1 && idx != 0)
                    idx -= 1;
            }       
            if (idx == 0){
                return j;
            }
            
        }
        return ans;
	}

};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}