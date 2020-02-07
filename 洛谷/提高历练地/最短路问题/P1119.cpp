#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200 + 10;
const int INF = 0x3f3f3f3f;
int map_[MAXN][MAXN], t[MAXN];
int n, m, q;

void update(int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map_[i][j] > map_[i][k] + map_[k][j]) {
                map_[i][j] = map_[j][i] = map_[i][k] + map_[k][j];
            }
        }
    }
    return;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map_[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        map_[i][i] = 0;
    }

    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        u++; 
        v++;
        map_[u][v] = map_[v][u] = w;
    }

    cin >> q;
    int x, y, ti, now = 1;
    while (q--) {
        cin >> x >> y >> ti;
        x++; 
        y++;
        while (t[now] <= ti && now <= n) {
            update(now);
            now++;
        }

        if (t[x] > ti || t[y] > ti) {
            //x或者y没有建好
            cout << -1 << endl;
        }

        else if (map_[x][y] == INF) {
            cout << -1 << endl;
        } else {
            cout << map_[x][y] << endl;
        }
    }

    return 0;
}