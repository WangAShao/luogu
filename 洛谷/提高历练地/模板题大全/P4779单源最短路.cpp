#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;
typedef pair<int, int> pa;
int n, m, s, cnt, dis[MAXN], head[MAXN], vis[MAXN];

struct cmp {
    bool operator() (const pa p1, const pa p2) {
        return p1.second > p2.second;
    }
};

priority_queue<pa, vector<pa>, cmp > q;

struct Edge {
    int to;
    int w;
    int nxt;
} e[MAXM];

void addEdge (int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

int main() {
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = 2e9;
    }

    dis[s] = 0;
    q.push(make_pair(s, 0));

    while (!q.empty()) {
        int now = q.top().first;
        int val = q.top().second;
        q.pop();
        if (vis[now]) {
            continue;
        }
        vis[now] = 1;
        for (int i = head[now]; i; i = e[i].nxt) {
            int to = e[i].to;

            if (dis[to] > dis[now] + e[i].w) {
                dis[to] = dis[now] + e[i].w;
                q.push(make_pair(to, dis[to]));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }

    return 0;

}

