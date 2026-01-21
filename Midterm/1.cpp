#include <bits/stdc++.h>
using namespace std;

vector<int> Hs;




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> sorted_hs;
    int N;
    cin >> N;
    for(int i=0; i<N;i++){
        int a;
        cin >> a;
        Hs.push_back(a);
        sorted_hs.push_back(a);
    }

    sort(sorted_hs.begin(),sorted_hs.end());
    

    for(int i = 0; i<N; i++){
        int a = Hs[i];
        auto b = lower_bound(sorted_hs.begin(),sorted_hs.end(),a);

        if(a== sorted_hs[0] and sorted_hs[0] != sorted_hs[1]){
            cout << abs(*(b+1) -a) << "\n";
            continue;
        }
        if(a == sorted_hs[N-1] and sorted_hs[N-1] != sorted_hs[N-2]){
             cout << abs(*(b-1) -a) << "\n";
            continue;
        }
        int low = abs(*(b-1) -a);
        int high = abs(*(b+1) -a);
        int ans = min(low,high);
        cout << ans << "\n";
    }
}