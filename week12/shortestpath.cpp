#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAX_N = 100010;

int n,m;
vector<int> adj[MAX_N];
vector<int> lengths[MAX_N];
int deg[MAX_N];
int parents[MAX_N];
void read_input()
{
  cin >> n >> m;
  for(int u=0; u<n; u++) {
    deg[u] = 0;
  }

  for(int i=0; i<m; i++) {
    int u,v,l;
    cin >> u >> v >> l;  u--;  v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++; deg[v]++;
    lengths[u].push_back(l);
    lengths[v].push_back(l);
  }
}
const int INFINITY = 1000000000;
bool visited[MAX_N];
int D[MAX_N];
set<pair<int,int>> Q;

void dijkstra(int s)
{
  for(int u=0; u<n; u++) {
    visited[u] = false;
    D[u] = INFINITY;
    parents[u] = -1;
  }
  D[s] = 0;
  Q.insert({ D[s], s });

  for(int i=0; i<n; i++) {
    // find u that minimizes D[u] & visited[u] == false
    if(Q.empty())
      return;
    auto lu = *(Q.begin());
    Q.erase(Q.begin());
    int u = lu.second;
    
    visited[u] = true;
    for(int d = 0; d < deg[u]; d++) {
      int v = adj[u][d];
      int l = lengths[u][d];
      if(D[v] > D[u] + l) {
        Q.erase({ D[v], v });
        D[v] = D[u] + l;
        parents[v] = u;
        Q.insert({ D[v], v });
      }
    }
  }
}

int main()
{
  read_input();
  dijkstra(0);
  cout << D[n-1] << endl;
}