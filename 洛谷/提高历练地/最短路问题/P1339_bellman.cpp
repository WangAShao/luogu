#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2500 + 10;
const int MAXM = 6200 + 10;
const int INF = 2e9;
int u[MAXM], v[MAXM], dis[MAXN], w[MAXM];
bool check;
int n, m, s, t;

int main() {
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }

    dis[s] = 0;
    for (int i = 1; i < n; i++) {
        check = true;
        for (int i = 1; i <= m; i++) {
            if (dis[v[i]] > dis[u[i]] + w[i]) {
                check = false;
                dis[v[i]] = dis[u[i]] + w[i];
            }

            if (dis[u[i]] > dis[v[i]] + w[i]) {
                check = false;
                dis[u[i]] = dis[v[i]] + w[i]; 
            }
        }

        if (check) {
            break;
        }
    }

    cout << dis[t];
    return 0;
}