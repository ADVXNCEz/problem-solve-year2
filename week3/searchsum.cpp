#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    vector<int> book;
    cin >> N>>K;
    int sum=0;
    int cost;
    for(int i=0; i<N; i++){
        cin >> cost;
        sum += cost;
        book.push_back(sum);
    }
    auto first = book.begin();
    auto last = book.end();

    for(int i=0; i<K; i++){
        cin >> cost;
        auto it1 = lower_bound(first,last,cost);
        auto it2 = it1;
        
        if (it2 != first) --it2;

        if(*it1 == cost){
            cout<< it1 - first + 1 << "\n";
        }else if(*it2 > cost){
            cout << 0 << "\n";
        }else{
            cout<< it2 - first + 1 << "\n";
        }

        
    }


}