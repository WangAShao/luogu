#include <bits/stdc++.h>

using namespace std;
int t, m;
int f[1100], c[110], w[110];

int main() {
    cin >> t >> m;

    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> w[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= 0; j--) {
            if (j >= c[i]) {
                f[j] = max(f[j], f[j - c[i]] + w[i]);
            }
        }
    }

    cout << f[t];
    return 0;
}