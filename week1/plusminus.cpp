#include <bits/stdc++.h>
using namespace std;

int check[20000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int num,sum=0;
    char s='+';
    for(int i = 0; i<N+N-1;i++){
        if(i%2 == 0){
            cin >> num;
            if(s == '+')sum+=num;
            else sum -=num;
        }
        else cin>> s;

    }

    cout << sum; 

}