#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll L, N;
    cin >> L >> N;

    ll left = 1, right = 200000; 
    ll ans = 0;

    while(left <= right){
        ll mid = (left + right) / 2;
        ll nub = L * mid * (mid + 1) / 2;

        if(nub >= N){
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
