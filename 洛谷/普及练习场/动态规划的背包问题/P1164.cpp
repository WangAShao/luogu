#include <bits/stdc++.h>

using namespace std;
int n, m;
int f[110][10010], w[110];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i <= n; i++) {
        f[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] += f[i - 1][j];
            if (j >= w[i]) {
                f[i][j] += f[i - 1][j - w[i]];
            }
        }
    }

    cout << f[n][m];
    return 0;
}