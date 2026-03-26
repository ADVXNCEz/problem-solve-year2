#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_N 50001

int n, m, s, t;

struct Edge {
    int to, color;
};

vector<Edge> adj[MAX_N];

// dist[node][state]: 0=free, 1=red, 2=black
int dist[MAX_N][3];

void solve() {
    memset(dist, -1, sizeof(dist));

    // BFS: {node, state}
    queue<pair<int,int>> q;
    dist[s][0] = 0;
    q.push({s, 0});

    while (!q.empty()) {
        auto [u, state] = q.front(); q.pop();

        for (auto& e : adj[u]) {
            int v = e.to;
            int c = e.color;

            // ตรวจสอบว่าข้ามได้ไหม
            if (c != 0 && state != 0 && state != c) continue;

            // คำนวณ new state
            int ns = (c == 0) ? state : c;

            if (dist[v][ns] == -1) {
                dist[v][ns] = dist[u][state] + 1;
                q.push({v, ns});
            }
        }
    }

    // หา minimum ใน 3 states ของ node t
    int ans = -1;
    for (int s = 0; s < 3; s++) {
        if (dist[t][s] != -1) {
            if (ans == -1 || dist[t][s] < ans)
                ans = dist[t][s];
        }
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    solve();
    return 0;
}