#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int n, a;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a;
        arr[i] = a;
    }
    int pos=n-1,neg=0;
    while(neg<pos){
        if (arr[neg] < 0)
            neg+=1;
        else{
            swap(arr[neg],arr[pos]);
            pos-=1;
            neg+=1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}