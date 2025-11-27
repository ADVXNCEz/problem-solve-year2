#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,K;
    cin >> N >> K;
    long long box[N];
    for(long long i =0;i<N; i++){
        cin >> box[i];
    }
    
    sort(box,box+N);
    long long top = box[0]*K;
    long long nub = 0;

    for(long long i =1;i<N; i++){
        if(top > (box[i])*(K-1))nub++;
    }

    cout << nub+1;
}