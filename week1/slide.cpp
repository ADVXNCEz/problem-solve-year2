#include <bits/stdc++.h>
using namespace std;

int check[20000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int box[N];
    for(int i = 0;i<N;i++){
        cin >> box[i];
    }

    int nub = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<i;j++){
            if(box[i] > box[j]){
                nub++;
            }
        }
    }
    cout << nub;
}