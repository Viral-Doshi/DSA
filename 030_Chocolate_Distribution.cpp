#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long dif=INT_MAX;
    for (int i=0; i<n-m+1; i++)
       dif = min(dif,a[m-1+i]-a[i]);
    return dif;
    }   
};

int main() {
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++){
			cin>>x;
			a.push_back(x);
		}		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;