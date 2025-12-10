#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;
    
    unordered_map<int,int> mp;
    for(int i=0; i<num;i++){
        int a;
        cin >> a;
        mp[a]++;
    }

    vector<pair<int,int>> vec(mp.begin(), mp.end());
    
    sort(vec.begin(),vec.end(),[](pair<int,int> a, pair<int,int> b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        });

    for(auto x : vec) 
        cout <<x.first<< "\n";



}