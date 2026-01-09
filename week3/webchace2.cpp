#include <bits/stdc++.h>
using namespace std;

int main(){
  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin >> N >> M;
    list<int> cache;
    unordered_set<int> in_cache;
    int sum = 0;
    
    for(int i = 0; i<M ; i++){
        int a;
        cin >> a;
        if(in_cache.find(a) == in_cache.end()){
            cache.push_back(a);
            in_cache.insert(a);
            sum++;
        }
        if((int)cache.size() > N){
                int old = cache.front();
                cache.pop_front();
                in_cache.erase(old);
        }
    }
    
    cout << sum;

}