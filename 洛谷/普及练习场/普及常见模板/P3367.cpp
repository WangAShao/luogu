#include <bits/stdc++.h>

using namespace std;

int n, m;
int f[10010];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    int x, y, z;
    for (int i = 1; i <= m; i++) {
        cin >> z >> x >> y;
        if (z == 1) {
            f[find(x)] = find(y);
        } else {
            int u = find(x);
            int v = find(y);
            if (u == v) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }

    return 0;
}