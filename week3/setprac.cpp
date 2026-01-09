#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    set<int> s1;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        s1.insert(a);
    }

    while(n--){
        int x;
        cin >> x;

        auto it1 = s1.lower_bound(x);
        auto it2 = it1;

        if (it2 != s1.begin()) --it2;
        else it2 = s1.end();   // no value < x

        int best;

        if (it1 == s1.end()) {
            best = *it2;
        } else if (it2 == s1.end()) {
            best = *it1;
        } else {
            best = (abs(*it1 - x) < abs(x - *it2) ? *it1 : *it2);
        }

        cout << best << "\n";
    }
}
