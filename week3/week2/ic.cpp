#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    list <int> l;
    string c;
    int n;

    for(int i=0;i<M;i++){
        cin >> c;
        if(c == "li"){
            cin >> n;
            l.push_front(n);}
        if(c == "ri"){
            cin >> n;
            l.push_back(n);
        }
        if(c == "lr" && !l.empty()){
            int num = l.front();
            l.pop_front();
            l.push_back(num);
        }
        if(c == "rr" && !l.empty()){
            int num = l.back();
            l.pop_back();
            l.push_front(num);
        }

    }

    for(auto x:l)cout << x << "\n";
}