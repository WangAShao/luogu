#include <bits/stdc++.h>

using namespace std;
int f[27][30002], v[27], w[27];

int main() {
    int n, m, i, j;
    cin >> n >> m;

    for (i = 1; i <= m; i++) {
        cin >> v[i] >> w[i];
        w[i] *= v[i];
    }

    for (i = 1; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (j >= v[i]) {
                f[i][j] = max(f[i-1][j], f[i - 1][j - v[i]] + w[i]);
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }

    cout << f[m][n];
}