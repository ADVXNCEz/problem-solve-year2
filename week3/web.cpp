#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    list<int> cache;
    int sum=0;
    for(int i = 0; i<M ; i++){
        int a;
        cin >> a;
        auto it = find(cache.begin(), cache.end(),a);
        if(it == cache.end()){
            cache.push_back(a);
            sum++;
            if(cache.size() > N)cache.pop_front();
        }
    }
    
    cout << sum;

}