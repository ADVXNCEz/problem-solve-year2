#include <bits/stdc++.h>
using namespace std;

int check[20000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K,T;
    cin >> N >> K >> T;
    int i = 0;
    check[i]=1;

    do{
        i = (i+K)%N;
        check[i]=1;
    }while(i != 0 && i != T-1 );


    int nub=0;
    for(int i=0;i<N;i++)if(check[i] == 1)nub++;
    cout << nub;
}