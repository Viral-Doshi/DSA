#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        map <int,int> m;
        int max_length=0,curr_length=0;
        
        for(int i=0; i<N; i++)
            if (m.find(arr[i]) == m.end())
                m[arr[i]] = 1;
                
        int counter = m.begin()->first;
        for(auto const& x: m){
            if (x.first == counter){
                curr_length+=1;
                counter++;
                continue;
            }
            else
                max_length = max(max_length,curr_length);
                curr_length = 1;
                counter = x.first;
                counter+=1;
        }
        return max(max_length,curr_length);
    }
};

int main(){
    int  t,n,i,a[100001];
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        Solution obj;
        cout<<obj.findLongestConseqSubseq(a, n)<<endl;
    }
      
    return 0;
}