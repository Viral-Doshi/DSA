#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}

int PalinArray(int a[], int n){
    string str,rev;
    for(int i=0; i<n; i++){
        str = to_string(a[i]);
        rev = string(str.rbegin(),str.rend());
        if (str != rev)
            return 0;
    }
    return 1;
}