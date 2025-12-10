#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n;
    cin >> m >> n;

    set<int> s1;
    for(int i=0; i<m;i++){
        int a;
        cin >> a;
        s1.insert(a);
    }

    for(int i=0; i<n; i++){
        int n;
        cin >> n;
        auto low = lower_bound(s1.begin(),s1.end(),n);

        if(lo)
}