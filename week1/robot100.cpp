#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    int x=0,y=0;

    for(int i = 0; i < s.size() ; i++){
        if (s[i] == 'N') y++;
        if (s[i] == 'E') x++;
        if (s[i] == 'W') x--;
        if (s[i] == 'S') y--;
        if (s[i] == 'Z') {x = 0,y=0;}

    }

    cout << x << " " << y;
}