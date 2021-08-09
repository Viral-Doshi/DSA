#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool find3Numbers(int A[], int n, int X){
        sort(A,A+n);
        int x,l,r;
        for(int i = 0; i < n - 1; i++){
            x = X - A[i];
            l = i + 1;
            r = n - 1;
            while(l < r){
                if(A[l] + A[r] > x)
                    r--;
                else if(A[l] + A[r] < x)
                    l++;
                else
                    return true;
            }            
        }
        return false;
    }
};

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
