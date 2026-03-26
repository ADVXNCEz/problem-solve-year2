
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, T;
    cin >> N >> T;

    vector<long long> Y(N + 1), Z(N + 1);
    vector<int> X(N + 1);

    if (T == 1) {

        for (int i = 1; i <= N; i++) cin >> Y[i];

        X[1] = (Y[1] > N ? 1 : 0);
        for (int i = 2; i <= N; i++) {
            X[i] = (Y[i] > Y[i - 1] ? 1 : 0);
        }
    } 
    else {

        for (int i = 1; i <= N; i++) cin >> Z[i];

        Y[1] = Z[1];


        for (int i = 2; i <= N; i++) {
            long long y_prev = Y[i - 1];

            long long cand1 = y_prev + 1;
            long long cand2 = y_prev - 1;

            bool ok1 = false, ok2 = false;


            if (Z[i] == cand1 + 2 * y_prev) ok1 = true;

            if (Z[i] == cand1 + y_prev) ok1 = true;

            if (Z[i] == cand2 + 2 * y_prev) ok2 = true;
            if (Z[i] == cand2 + y_prev) ok2 = true;


            if (ok1 && !ok2) Y[i] = cand1;
            else if (!ok1 && ok2) Y[i] = cand2;
            else {

                if (ok1) Y[i] = cand1;
                else Y[i] = cand2;
            }
        }


        X[1] = (Y[1] > N ? 1 : 0);
        for (int i = 2; i <= N; i++) {
            X[i] = (Y[i] > Y[i - 1] ? 1 : 0);
        }
    }


    for (int i = 1; i <= N; i++) cout << X[i] << "\n";

    return 0;
}
