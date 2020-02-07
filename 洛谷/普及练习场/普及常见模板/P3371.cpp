#include <bits/stdc++.h>

using namespace std;

const int inf=2147483647;
int n, m, s;
long long dis[10010];
int u[500010], v[500010], w[500010];
bool flag;

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
    }

    dis[s] = 0;
    for (int k = 1; k <= n - 1; k++) {
        flag = false;
        for (int i = 1; i <= m; i++) {
            if (dis[v[i]] > dis[u[i]] + w[i]) {
                dis[v[i]] = dis[u[i]] + w[i];
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    return 0;
}