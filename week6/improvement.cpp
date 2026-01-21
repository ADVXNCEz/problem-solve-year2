#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> x(N);
    for(int i = 0; i < N; i++) cin >> x[i];

    long long MaxR = -1;
    int cnt3 = 0, cnt2 = 0;

    for(int i = N - 1; i >= 0; i--) {
        if (MaxR >= 3 * x[i]) {
            cnt3++;
        } else if (MaxR >= 2 * x[i]) {
            cnt2++;
        }
        MaxR = max(MaxR, x[i]);
    }

    cout << cnt3 << " " << cnt2 << "\n";
    return 0;
}
