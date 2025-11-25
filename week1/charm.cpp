#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int sum = 0;
    int nub = 0,now;
    int maxnub = 0;
    cin >> N;
    int box[N];

    for(int i = 0; i<N; i++)cin >> box[i];
    sort(box,box+N);

    now = box[0];
    for(int i = 0; i<N; i++){
        if(now == box[i]) nub ++;
        else {
            maxnub = max(maxnub,nub);
            nub = 1;
            now = box[i];
        }
    }

    cout << maxnub;
    return 0;
}