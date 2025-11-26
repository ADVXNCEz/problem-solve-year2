#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> P(3);
    for(int i = 0; i<3; i++)cin >> P[i];
    cin >> N;

    vector<int> box(3);
    for(int i = 0; i<N; i++){
        int price;
        cin >> price;
        box[price-1]++;
    }

    int mn = min(P[0]*box[0], min(P[1]*box[1], P[2]*box[2]));

    cout << mn;
}