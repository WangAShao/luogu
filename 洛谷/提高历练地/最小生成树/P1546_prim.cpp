#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100 + 10;
int n, cnt, ans;
bool vis[MAXN];

struct Edge{
    int u;
    int v;
    int w;
    bool operator <(const struct Edge& n) const {
        return w > n.w;
    }
};

vector <Edge> g[MAXN];
priority_queue <Edge> edge;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (w == 0) continue;
            g[i].push_back(Edge{i, j, w});
        }
    }

    vis[1] = true;
    for (int i = 0; i < g[1].size(); i++) {
        edge.push(g[1][i]);
    }

    while (cnt < n - 1)
    {
        int w = edge.top().w;
        int v = edge.top().v;
        edge.pop();
        
        if (vis[v]) {
            //已经访问过了
            continue;
        }

        vis[v] = true;
        ans += w;
        cnt++;
        for (int i = 0; i < g[v].size(); i++) {
            if (!vis[g[v][i].v]) {
                edge.push(g[v][i]);
            }
        }
    }
    
    cout << ans;
    return 0;
}