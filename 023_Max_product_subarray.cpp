#include <bits/stdc++.h>
using namespace std;
class Solution{
public:

    long long maxProduct_Inovative(int* arr, int n){
        long long minVal = arr[0], maxVal = arr[0], maxProduct = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0)
                swap(maxVal, minVal);
            maxVal = max((long long)arr[i], maxVal * arr[i]);
            minVal = min((long long)arr[i], minVal * arr[i]);
            maxProduct = max(maxProduct, maxVal);
        }
        return maxProduct;
}

	long long maxProduct(int *arr, int n) {
	    bool start = true, first_neg = false;
        long long max_product = -1000000, curr_product  = 1, till_first_neg = 1, after_last_neg = 1;
        for(int i=0; i<n; i++){
            if (arr[i] == 0){
                if (curr_product<0)
                    curr_product = curr_product/max(till_first_neg,after_last_neg);
                max_product = max(max_product,curr_product);
                curr_product = 1;
                till_first_neg = 1;
                after_last_neg = 1;
                first_neg = false;
                continue;
            }

            curr_product *= arr[i];
            after_last_neg *= arr[i];
            if (arr[i] < 0){
                if(!first_neg)
                    till_first_neg = curr_product;
                    first_neg = true;
                after_last_neg = arr[i];
            }
        }
        if (curr_product<0){
            cout << curr_product << " " << till_first_neg << " " << after_last_neg << endl;
            curr_product = curr_product/max(till_first_neg,after_last_neg);
        }
        return max(max_product,curr_product);
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}