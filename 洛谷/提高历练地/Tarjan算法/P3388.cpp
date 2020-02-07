#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e4 + 10;
const int MAXM = 2e5 + 10;
int n, m, cnt, id, ans, head[MAXN], dfn[MAXN], low[MAXN], cut[MAXN];

struct Edge {
    int to;
    int nxt;
} e[MAXM];

void addEdge (int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void tarjan (int u, int fa) {
    dfn[u] = low[u] = ++id;
    int child = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (!dfn[to]) {
            tarjan(to, fa);
            low[u] = min(low[u], low[to]);
            if (low[to] >= dfn[u] && u != fa) {
                cut[u] = 1;
            }   

            if (u == fa) {
                child++;
            }
        }

        low[u] = min(low[u], dfn[to]);
    }

    if (child >= 2 && u == fa) {
        cut[u] ==  1;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            ans++;
        }
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            cout << i << " ";
        }
    }

    return 0;
}