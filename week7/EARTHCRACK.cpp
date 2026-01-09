#include <bits/stdc++.h>
using namespace std;

int walk(int h, int l, map<int,map<int,int>> &MAP,int M,int N,map<int,map<int,int>>&sPath){

    if(h==M) return sPath[M][l] = MAP[M][l];     
    if(h==0){
        int minn = 1000000;
        for(int i = 1;i<=N;i++){
            if(sPath[1][i] == 0)walk(1,i,MAP,M,N,sPath);
            minn = min(minn, sPath[1][i]);
        }
        return minn;
    }
    int best_way = 1000000;

    if(sPath[h][l] != 0)return sPath[h][l];
    else{
        if(l+1<N+1) best_way = walk(h+1,l+1,MAP,M,N,sPath);
        if(l-1 > 0) best_way = min(walk(h+1,l-1,MAP,M,N,sPath),best_way);
        best_way = min(walk(h+1,l,MAP,M,N,sPath),best_way);
        return sPath[h][l] = best_way + MAP[h][l];

    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int i =0; i<T; i++){
        map<int,map<int,int>> MAPs,Spath;
        int M,N;
        cin >> M >> N;
        for(int j = 1; j<=M ; j++){
            for(int k = 1; k<=N ; k++){
                cin >> MAPs[j][k];
            }
        }
        cout << walk(0,0,MAPs,M,N,Spath)<< "\n";
    }



}