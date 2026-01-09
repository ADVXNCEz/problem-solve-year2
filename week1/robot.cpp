#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H1,H2,B1,B2;
    int X, Y;
    cin >>H1>>H2>>B1>>B2>>X>>Y;
    int ans = 0;

    for (int w = 0; w <= min(H1, B1); w++) {
        for (int b = 0; b <= min(H2, B2); b++) {

            int same = w + b;
            if (same > X + Y) continue;
            int h1 = H1 - w;
            int b1 = B1 - w;
            int h2 = H2 - b;
            int b2 = B2 - b;

            int diff = min(h1, b2) + min(h2, b1);
            int money = min(same, X) + min(diff, Y);
            ans = max(ans, money);
        }
    }

    cout <<ans<<endl;
    return 0;
    
}
