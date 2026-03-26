#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, T;
    cin >> N >> K >> T;

    vector<int> check(N, 0);

    int i = 0;
    check[0] = 1;

    while (true) {
        i = (i + K) % N;
        check[i] = 1;
        if (i == 0 || i == T-1) break;
    }

    int nub = 0;
    for (int x : check) if (x == 1) nub++;

    cout << nub;
}
