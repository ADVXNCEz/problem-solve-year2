#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> box;
vector<int> memo;
int n;

int best_group(int now){
    if(now == 0) return 0;
    if(now < 0) return INF;
    if(memo[now] != -1) return memo[now];

    int Least = INF;

    for(int i = 2; i <= 10; i++){
        if(now - i < 0) break;

        int mn = INT_MAX, mx = INT_MIN;
        for(int j = now - i; j < now; j++){
            mn = min(mn, box[j]);
            mx = max(mx, box[j]);
        }

        int prev = best_group(now - i);
        if(prev == INF) continue; 

        Least = min(Least, prev + (mx - mn));
    }

    return memo[now] = Least;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    box.resize(n);
    memo.assign(n + 1, -1);

    for(int i = 0; i < n; i++){
        cin >> box[i];
    }

    cout << best_group(n) << "\n";
}
