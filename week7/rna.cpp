#include <bits/stdc++.h>
using namespace std;

map<int,map<int,int>> dp;


int RNA(string str,int start,int final){
    if(start >= final || start >(str.size())-1 || final < 0 || final-start <= 4)return 0;

    for(int i = start; i < final; i++){
        c = ;
    }
    int a = RNA(str,start+1,final);
    int b = RNA(str,start,final-1);
    

    int maxx = max(a,b);

    if((str[start] == 'C' && str[final] == 'G') || 
       (str[start] == 'G' && str[final] == 'C') ||
       (str[start] == 'A' && str[final] == 'U') ||
       (str[start] == 'U' && str[final] == 'A') )
        maxx = max(maxx ,RNA(str,start+1,final-1)+1);


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