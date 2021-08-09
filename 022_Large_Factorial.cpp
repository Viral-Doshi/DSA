#include <bits/stdc++.h>
using namespace std;

int multiply(int arr[], int k, int size){
    int carry = 0;
    for(int i = 0; i < size; i++){
        int temp = arr[i]*k +carry;
        arr[i] = temp%10;
        carry = temp/10;
    }
    while(carry){
        arr[size] = carry % 10;
        carry /= 10;
        size++;
    }
    return size;
}
class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        int arr[10000], size = 1;
        arr[0] = 1;
        for(int i = 2; i <= N; i++)
            size = multiply(arr, i, size);
        for (int i=size-1; i>=0; i--)
            ans.push_back(arr[i]);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}