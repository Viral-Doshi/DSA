#include<bits/stdc++.h>
using namespace std;

double Median(int arr1[], int arr2[],int n,int m){
    //cout << n << " " << m << endl;
    if (n>m)
        return Median(arr2,arr1, m, n);
    
    int low = 0, high = n;
    while (low <= high){
        int part1 = (low + high)/2;
        int part2 = (m + n + 1)/2 - part1;
        int maxleft1 = (part1 == 0) ? INT_MIN : arr1[part1-1];
        int minright1 = (part1 == n) ? INT_MAX : arr1[part1];
        int maxleft2 = (part2 == 0) ? INT_MIN : arr2[part2-1];
        int minright2 = (part2 == m) ? INT_MIN : arr2[part2];

        if (maxleft1 <= minright2 && maxleft2 <= minright1){
            if ((m+n)%2 == 0)
                return (max(maxleft1,maxleft2) + min(minright1, minright2))/(double)2;
            return (double)max(maxleft1,maxleft2);
        }
        else if (maxleft1 > minright2)
            high = part1-1;
        else
            low = part1+1;
    }
}

int main(){
    int n,m,temp;
    cin >> n >> m;
    int* arr1 = new int[n];
    int* arr2 = new int[m];
    for(int i = 0; i < n; i++){
        cin >> temp;
        arr1[i] = temp;
    }
    for(int i = 0; i < m; i++){
        cin >> temp;
        arr2[i] = temp;
    }
    cout << Median(arr1,arr2,n,m);
}