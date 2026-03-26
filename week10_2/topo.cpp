#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100001

int n, m;
vector<int> adj[MAX_N];
int indeg[MAX_N];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        indeg[v]++;
    }

    // ใส่ทุก node ที่ in-degree = 0
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    // ถ้า process ได้ไม่ครบทุก node = มี cycle
    if ((int)order.size() < n) {
        printf("no\n");
    } else {
        for (int u : order) printf("%d\n", u);
    }

    return 0;
}