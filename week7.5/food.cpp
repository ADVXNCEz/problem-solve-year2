#include <bits/stdc++.h>
using namespace std;

vector<int> N_people;
int N;

struct DP {
    bool used;
    int val;
};

DP dp[5005][5005];

int bestgive(int Max_item, int item, int order){
    if(dp[item][order].used)
        return dp[item][order].val;

    int count;

    if(order + 1 == N){
        if(item >= N_people[order]){ 
            dp[item][order] = {true, 0};
            return 0;
    
    }
        if(item < N_people[order]){
            dp[item][order] = {true, N_people[order]};
            return  dp[item][order].val;
        }
    }

    if(item >= N_people[order]){
        int NO_give  = N_people[order] + bestgive(Max_item, Max_item, order+1);
        int Yes_give = bestgive(Max_item, item - N_people[order], order+1);
        count = min(NO_give, Yes_give);
    }

    if(item < N_people[order]){
        count = N_people[order] + bestgive(Max_item, Max_item, order+1);
    }

    dp[item][order] = {true,count}; 
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> N >> K;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        N_people.push_back(a);
    }

    cout << bestgive(K, K, 0);
}

