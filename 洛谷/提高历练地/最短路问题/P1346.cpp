#include <bits/stdc++.h>

using namespace std;
const int MAXN = 20010;
const int INF = 2e9;
int n, a, b, k, s;
int u[MAXN], v[MAXN], w[MAXN], dis[110], cnt;
bool check;
//把每一个车站看成一个点，将这个车站相连的第一个车站建立一条边权为0的边，对于它所相连的其他车站，建立边权为1的边；
int main() {
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }

    dis[a] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            if (j == 1) {
                cin >> s;
                u[++cnt] = i;
                v[cnt] = s;
                w[cnt] = 0;
            } else {
                cin >> s;
                u[++cnt] = i;
                v[cnt] = s;
                w[cnt] = 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        check = true;
        for (int j = 1; j <= cnt; j++) {
            if (dis[v[j]] > dis[u[j]] + w[j]) {
                dis[v[j]] = dis[u[j]] + w[j];
                check = false;
            }
        }

        if (check) {
            break;
        }
    }

    if (dis[b] == INF) {
        cout << -1;
        return 0;
    }
    cout << dis[b];
    return 0;
}