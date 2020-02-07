#include <bits/stdc++.h>

using namespace std;

bool vis[110];
int m, n, s;

int main() {
    cin >> n >> m;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < m; i++) {
            if (++s > n) s = 1;
            if (vis[s]) i--;
        }
        printf("%d ", s);
        vis[s] = true;
    }
    return 0;
}