#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10010;
const int MAXM = 200010; //由于双向边, 所以边的大小要开双倍
int n, m, tot = 0, sum[3], ans = 0;
int used[MAXN], h[MAXN];//h[i]记录点i在邻接表中指向的第一条边

struct Edge {
    int v;
    int next;//next记录这条边在邻接表中指向同端点的另一条边
} edge[MAXM];

void addEdge(int u, int v) {
    tot++;
    edge[tot].v = v;
    edge[tot].next = h[u];
    h[u] = tot;
}

queue<int> q;

bool bfs(int start) {
    used[start] = 1; //该点使用过了, 故染色
    sum[1] = 1; sum[2] = 0;
    q.push(start);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int k = h[u]; k; k = edge[k].next) {
            int v = edge[k].v;
            if (used[v] == used[u]) return 1;
            if (used[v] == 0) {
                used[v] = used[u] % 2 + 1;
                sum[used[v]]++;
                q.push(v);
            }
        }
    }

    return 0;
}

int main() {
    cin >> n >> m;

    while (m--) {
        int a1, a2;
        cin >> a1 >> a2;

        addEdge(a1, a2);
        addEdge(a2, a1);
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            continue;
        }

        if (bfs(i)) {
            cout << "Impossible";
            return 0;
        }

        else ans += min(sum[1], sum[2]);
    }

    cout << ans;

    return 0;
}