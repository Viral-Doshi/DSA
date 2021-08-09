#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,temp;
    cin >> n >> m;
    map <int,int> elements;
    for(int i=0; i<n; i++){
        cin >> temp;
        elements.insert(pair<int,int>(temp,1));
    }
    for(int i=0; i<m; i++){
        cin >> temp;
        if (elements.find(temp) == elements.end())
            elements.insert(pair<int,int>(temp,1));
    }
    for(auto it = elements.begin(); it != elements.end(); it++)
        cout << it->first << " ";
    return 0;
}