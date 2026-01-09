#include <bits/stdc++.h>
using namespace std;

map<int,map<int,int>> dp;


int RNA(string str,int start,int final){
    if(start > final) return 0;

    if(dp[start][final] == 0) dp[start][final] = RNA(str,start+1,final);
    int maxx = dp[start][final];
    

    for(int i = start+5; i < final+1; i++){
        if((str[start] == 'C' && str[i] == 'G') || 
        (str[start] == 'G' && str[i] == 'C') ||
        (str[start] == 'A' && str[i] == 'U') ||
        (str[start] == 'U' && str[i] == 'A') ){
            maxx = max(maxx ,RNA(str,start+1,i-1) + 1 + RNA(str,i+1,final));
        }
    }


    return maxx;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int Size = (str.size())-1;
    cout << RNA(str,0,Size);
}