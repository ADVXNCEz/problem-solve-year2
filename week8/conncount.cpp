#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int parents[MAX_N];

void read_input(){

    cin >> n >> m;
    for(int u = 0; u < n; u++)
        deg[u] = 0;

    for(int i =0; i<m; i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        deg[u]++;
        adj[v].push_back(u);
        deg[v]++;
    }
}

void init(){
    for(int u = 0; u<n ;u++){
        visited[u] = false;
        parents[u] = -1;
    }
}

void dfs(int u ){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            parents[v] = u;
            dfs(v);
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    init();
    int conn_comp = 0;
    for(int u = 0; u < n; u++){
        if(!visited[u]){
            dfs(u);
            conn_comp++;
        }
    }
    cout << conn_comp << "\n";
    return 0;
}