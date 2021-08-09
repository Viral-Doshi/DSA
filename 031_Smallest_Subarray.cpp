#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        int tot = 0, num = INT_MAX, p1=0, p2=0;
        while(true){
            if (arr[p1] > x)
                return 1;
            else if (tot <= x && p2 == n){
                return num;
            }
            else if (tot <= x){
                tot+=arr[p2];
                p2++;
            }
            else{
                num = min(num, p2-p1);
                tot-=arr[p1];
                p1++;
            }
        }
        return num;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}