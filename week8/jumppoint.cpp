#include <bits/stdc++.h>
using namespace std;

int N, R;
struct Node {
    int x, y;
};

Node g[1005];
bool visited[1005];
int dista[1005];
queue<int> Q;

int dist2(int u, int v) {
    int dx = g[u].x - g[v].x;
    int dy = g[u].y - g[v].y;
    return dx*dx + dy*dy;
}

void bfs() {
    Q.push(0);
    visited[0] = true;
    dista[0] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v = 0; v <= N+1; v++) {
            if (!visited[v] && dist2(u, v) <= R*R) {
                visited[v] = true;
                dista[v] = dista[u] + 1;

                if (v == N+1) {
                    cout << dista[v];
                    return;
                }
                Q.push(v);
            }
        }
    }

    cout << "-1"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R;
    for (int i = 1; i <= N; i++) {
        cin >> g[i].x >> g[i].y;
    }

    g[0]   = {0, 0};
    g[N+1] = {100, 100};

    bfs();
}
