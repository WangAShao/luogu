#include <bits/stdc++.h>

using namespace std;
const int MAXN = 300 + 10;
const int MAXM = 200020;
int n, m, fa[MAXN], cnt, ans;

struct Edge {
    int u;
    int v;
    int w;
} edge[MAXM];

bool cmp (Edge a, Edge b) {
    return a. w < b.w;
}

int find (int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void union_ (int x, int y) {
    int fx = find(x);
    int fy = find(y);

    fa[fx] = fy;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }

    sort (edge + 1, edge + 1 + m, cmp);

    for (int i = 1; i <= m; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;

        if (find(u) == find(v)) {
            continue;
        }

        cnt++;
        ans = w;
        union_(u, v);
        if (cnt == n - 1) {
            break;
        }
    }

    cout << n - 1 << " " << ans << endl;
    return 0;   
}