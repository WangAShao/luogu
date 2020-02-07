#include <bits/stdc++.h>

using namespace std;
vector <int> g[1000010];
queue <int> q;
int dep[1000010], cnt[1000010]; //dep是每个点对源点的深度, cnt储存答案, 即到点i的最短路的个数
bool vis[1000010];//判断点是否使用
const int Mod = 100003;

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dep[1] = 0;
    vis[1] = 1;
    q.push(1);
    cnt[1] = 1;

    while (!q.empty()) { //bfs核心代码
        int x = q.front();
        q.pop();

        for (int i = 0; i < g[x].size(); i++) {
            int t = g[x][i];
            if (!vis[t]) {
                vis[t] = 1;
                dep[t] = dep[x] + 1;
                q.push(t);
            }

            if (dep[t] == dep[x] + 1) {
                cnt[t] = (cnt[t] + cnt[x]) % Mod;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}