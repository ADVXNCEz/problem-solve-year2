#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int L,N;
    cin >> L >> N;
    int sum = 0;
    for(int i=1; i<=L ;i++){
        sum +=i*i;
        if(sum == N){
            cout << L-i;
            break;
        }
        else if(sum > N) {
            cout << L-i+1;
            break;
        }
    }

}