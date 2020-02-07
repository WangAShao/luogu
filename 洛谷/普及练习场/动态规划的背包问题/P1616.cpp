#include <bits/stdc++.h>

using namespace std;
int t, m;
int f[100010], c[10010], w[10010];

int main() {
    cin >> t >> m;

    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> w[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= t; j++) {
            if (j >= c[i]) {
                f[j] = max(f[j], f[j - c[i]] + w[i]);
            }
        }
    }

    cout << f[t];
    return 0;
}