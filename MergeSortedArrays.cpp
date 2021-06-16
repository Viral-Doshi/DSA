#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
int nextDif(int dif){
    if (dif<=1)
        return 0;
    return (dif/2 + dif%2);
}
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i, j, dif = n+m;
	    for(dif = nextDif(dif); dif>0; dif = nextDif(dif)){
	        for(i=0; i+dif <n; i++){
	            if (arr1[i] > arr1[i+dif])
	                swap(arr1[i],arr1[i+dif]);
	        }
	    if (dif > n) j = dif-n;
	    else j=0;
	    for(; i < n && j < m; i++,j++){
	        if (arr1[i] > arr2[j])
	                swap(arr1[i],arr2[j]);
	    }
	    if (j < m){
	        for(j=0; j+dif < m; j++){
	            if (arr2[j] > arr2[j+dif])
	                swap(arr2[j],arr2[j+dif]);
	        }
	    }
	    }
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int *arr1 = new int[n];
        int *arr2 = new int[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}