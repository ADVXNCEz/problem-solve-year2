#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll num;
    cin >> num;

    unordered_map<ll,ll> mp;
    for(ll i=0; i<num;i++){
        ll a;
        cin >> a;
        if(a == 1){
            ll A;
            ll B;
            cin >> A >> B;
            mp[A] += B;
        }
        if(a == 2){
            ll A;
            cin >> A;
            cout << mp[A] << "\n";
        }
        if(a == 3){
            ll A;
            ll B;
            cin >> A >> B;
            if(mp[A] >= B){
                mp[A] -= B;
                cout << B << "\n";
            }else{
                cout << mp[A] << "\n";
                mp[A] = 0;
            }
            
        }

    }
}