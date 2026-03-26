#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n[7];
    int caseNum = 1;

    while (true) {
        for (int i = 1; i <= 6; i++) {
            cin >> n[i];
        }

        bool allZero = true;
        for (int i = 1; i <= 6; i++) {
            if (n[i] != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) break;

        int total = 0;
        for (int i = 1; i <= 6; i++) {
            total += i * n[i];
        }

        cout << "Collection #" << caseNum++ << ":\n";

        if (total % 2 != 0) {
            cout << "Can't be divided.\n\n";
            continue;
        }

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int value = 1; value <= 6; value++) {
            int cnt = n[value];
            int power = 1;
            while (cnt > 0) {
                int take = min(power, cnt);
                int weight = take * value;

                for (int j = target; j >= weight; j--) {
                    if (dp[j - weight])
                        dp[j] = true;
                }

                cnt -= take;
                power <<= 1;
            }
        }

        if (dp[target])
            cout << "Can be divided.\n\n";
        else
            cout << "Can't be divided.\n\n";
    }

    return 0;
}
