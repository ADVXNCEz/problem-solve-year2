#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long M;
    cin >>M;

    list<long long> l;
    char c;
    long long n;
    for(long long i =0;i<M;i++){
        cin>>c>>n;
        if(c == 'I')l.push_front(n);
        
        else {
            if(c == 'A')l.push_back(n);
            else{
                if(n >= 0 && n <= l.size()){
                    auto it = l.begin();
                    advance(it, n-1); 
                    l.erase(it);
                }
            }
        }
    }

    for(long long x:l)cout << x << "\n";

}