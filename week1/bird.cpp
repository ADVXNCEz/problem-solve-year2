#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 0; i<N; i++) cin >> P[i];

    int nub = 0;

    for(int i = 1; i<N-1; i++){ 
        if(P[i]>P[i+1] && P[i]>P[i-1])nub++;
    }

    if(P[0]>P[1])nub++;
    if(P[N-1]>P[N-2])nub++;
    cout << nub;
}