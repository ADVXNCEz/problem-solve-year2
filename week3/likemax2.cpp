#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    unordered_map<int,int> cnt;  
    map<int, set<int>> freq;       

    for(int i = 0; i < N; i++){
        int type, id;
        cin >> type >> id;

        int oldc = cnt[id];

        if(oldc > 0){
            freq[oldc].erase(id);
            if(freq[oldc].empty()) freq.erase(oldc);
        }

        if(type == 1) cnt[id]++;   
        else cnt[id]--;               

        int newc = cnt[id];
        if(newc > 0){
            freq[newc].insert(id);
        }


        int maxLike = freq.rbegin()->first;
        int ans = *freq[maxLike].rbegin(); 

        cout << ans << "\n";
    }
}
