#include<bits/stdc++.h>
using namespace std;

int N,Q;

char maze[22][22];
bool visit[22][22][11];


void input(){
    cin >> N >> Q;
    for(int i=1; i<=N ;i++){
        string str;
        cin >> str;
        for(int j = 1; j <=N ;j++){
            maze[i][j]=str[i-1];
        }
    }
}


void bfs(int x,int y,int X,int Y,int key,int times){
    visit[22][22][times] = true;
    queue<pair<int,int>> Que;
    Que.push({x,y});
    int walk_x[4] = {1,-1,0,0};
    int walk_y[4] = {0,0,1,-1};

    while(!Que.empty()){
        




    }







    cout << "no";
    return;
}   




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for(int i = 0; i<Q; i++){
        int Sx,Sy,Ex,Ey;
        cin >> Sx>> Sy >> Ex >> Ey;
        bfs(Sx,Sy,Ex,Ey,1,i);
    }

}