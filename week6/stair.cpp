#include <bits/stdc++.h>
using namespace std;

map<int, map<int, int> > dp;

int step(int h,int jump,int nub){
    if(h==0)return 1;
    if(h<0)return 0;
    
    int sum = nub;

    for(int i = 1;i<=jump+1; i++){
        if(dp[h-i][jump] != 0)sum += dp[h-i][jump];
        else {
            if(h-i >= 0)
            dp[h-i][jump] = step(h-i,jump,nub);
            sum += dp[h-i][jump] ;
        }
    }
    return sum%9377;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    int ans = step(N,K,0);
    cout << ans;
}