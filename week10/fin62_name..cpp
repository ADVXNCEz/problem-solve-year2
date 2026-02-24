#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string name;
    string text;
    cin >> name >> text;
    //cout << name <<" "<< text;
    int nub = 0;
    int l = name.length();
    int count = 0;
    for(int i =0 ; i< text.length(); i++){
        if(name[nub] == text[i]){
            nub++ ;
            if(nub == l){
                nub %= l;
                count ++;
            }
        }

    }

    cout << count;
}
