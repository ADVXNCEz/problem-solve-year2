#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_N 100001

int n, m;
vector<int> adj[MAX_N];
int color[MAX_N]; // -1 = ยังไม่ได้ระบายสี, 0 หรือ 1

bool bfs(int start) {
    queue<int> q;
    color[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u]; // สีตรงข้าม
                q.push(v);
            } else if (color[v] == color[u]) {
                return false; // สีเดียวกัน = ไม่ใช่ bipartite
            }
        }
    }
    return true;
}

int main() {
    int k;
    scanf("%d", &k);

    while (k--) {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) adj[i].clear();
        memset(color, -1, sizeof(int) * (n + 1));

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!bfs(i)) {
                    ok = false;
                    break;
                }
            }
        }

        printf("%s\n", ok ? "yes" : "no");
    }
    return 0;
}