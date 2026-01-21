#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> H(N + 1), Minn(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> H[i];
        if(i == 1) Minn[i] = H[i];
        else Minn[i] = min(Minn[i - 1], H[i]);
    }

    while(Q--){
        int T;
        long long x;
        cin >> T >> x;

        if(T == 1)cout << Minn[x] << "\n";
        else{
            long long k = x;

            if(Minn[1] < k){
                cout << 0 << "\n";
                continue;
            }
            int l = 1, r = N, ans = 0;
            while(l <= r){
                int mid = (l + r) / 2;
                if(Minn[mid] >= k){
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
