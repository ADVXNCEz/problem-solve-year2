#include <bits/stdc++.h>
using namespace std;

void doit(const vector<size_t> &Y, vector<size_t> &box)
{
    vector<size_t> L(Y.size());
    size_t cnt = 0;
    for (size_t i = 0; i < Y.size(); ++i)
    {
        size_t pos = lower_bound(L.begin(), L.begin() + cnt, Y[i])- L.begin();
        L[pos] = Y[i];
        if (pos == cnt)
            ++cnt;
        box[i] = pos + 1;
    }
}

int main()
{  
    size_t N;
    while (cin >> N)
    {
        vector<size_t> S(N);
        for (int i = 0; i < N; ++i)cin >> S[i];
        vector<size_t> box(N), box2(N);
        doit(S, box);
        reverse(S.begin(), S.end());
        doit(S, box2);
        reverse(box2.begin(), box2.end());

        size_t maxLIS = 0;
        for (size_t i = 0; i < box.size(); ++i)
        {
            maxLIS = max(maxLIS, 2 * min(box[i], box2[i]) - 1);
        }
        cout << maxLIS << "\n";
    }
    return 0;
}