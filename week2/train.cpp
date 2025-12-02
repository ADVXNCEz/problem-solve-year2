#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    vector<list<ll>> vec(100050,list<ll>(0));


    char c;
    ll k,j;

    for(int i =0; i<M; i++){
        cin >> c >> k >> j;
        if(c == 'N'){
            vec[j].push_back(k);
        }
        if(c == 'M'){
            if(!vec[k].empty())
            vec[j].splice(vec[j].end(),vec[k]); 
        }
    }

    for(auto &v : vec){
        for(auto x : v) cout << x << "\n";
    }

}