#include <bits/stdc++.h>
using namespace std;

map<int,map<int,int>> MAPs;
struct DP {
    bool used;
    int val;
};
DP dp[300][300];

int H,L,B;

int min_cost(int h, int l){
    if(dp[h][l].used == true)return dp[h][l].val;

    int cost = INT_MAX;
    if(h == 1 && l == 1){
        for(int i = 2 ;i<=H;i++){
            cost = min(cost,min_cost(i,1));
        }
    }

    if(l == L){
         dp[h][l] = {true,MAPs[h][l]};
        return dp[h][l].val;
    }

    if(h != H){
        int down = B+MAPs[h][l]+min_cost(h+1,l+1);
        cost = min(cost,down);
    }
    if(h != 1){
        int up = B+MAPs[h][l]+min_cost(h-1,l+1);
        cost = min(cost,up);
    }
    int next = MAPs[h][l]+min_cost(h,l+1);
    cost = min(cost,next);

    dp[h][l] = {true,cost};
    return dp[h][l].val;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> L >> B;

    for(int i = 1;i<=H;i++){
        for(int j=1; j<=L; j++){
        int a ;
        cin >> a;
        MAPs[i][j] = a;
        }
    }

    cout << min_cost(1,1);

}