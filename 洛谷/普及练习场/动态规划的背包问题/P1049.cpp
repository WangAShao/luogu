#include <bits/stdc++.h>

using namespace std;
int v, n;
int f[20010], w[40];

int main() {
    cin >> v >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= 0; j--) {
            if (j >= w[i]) {
                f[j] = max(f[j], f[j - w[i]] + w[i]);
            }
        }
    }

    cout << v - f[v];
    return 0;
}