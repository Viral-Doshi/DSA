#include <iostream>
using namespace std;
int minSwap(int *arr, int n, int k);

int main() {
	int t,n,k;
	cin>>t;
	while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}


int minSwap(int *arr, int n, int k) {
    int count = 0, curr_count=0, max_count;
    for(int i=0;i<n;i++)
        if (arr[i] <= k)
            count++;
    for(int i = 0; i < count; i++){
        if (arr[i] <= k)
            curr_count++;
    }
    max_count = curr_count;
    for(int i=0; i<n-count; i++){
        if (arr[i] <= k)
            curr_count--;
        if (arr[i+count] <= k)
            curr_count++;
        max_count = max(max_count,curr_count);        
    }
    return count-max_count;
}
