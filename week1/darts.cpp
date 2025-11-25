#include <bits/stdc++.h>
using namespace std;

int cal(double range, int score){
    if (range <= 2.0) score += 5;
    else if (range <= 4.0) score += 4;
    else if (range <= 6.0) score += 3;
    else if (range <= 8.0) score += 2;
    else if (range <= 10.0) score +=1;
    else score +=0;

    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int x, y;
    double d;
    int score = 0;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        d = sqrt(x * x + y * y);   // FIXED
        score = cal(d, score);
    }

    cout << score;
    return 0;
}
