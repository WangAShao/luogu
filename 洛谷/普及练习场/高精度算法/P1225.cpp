#include <bits/stdc++.h>

using namespace std;
int n, len;
int f[5010][5010];

void add(int k) {
    for (int i = 1; i <= len; i++) {
        f[k][i] = f[k - 1][i] + f[k - 2][i];
    }

    for (int i = 1; i <= len; i++) {
        if (f[k][i] >= 10) {
            f[k][i + 1] += f[k][i] / 10;
            f[k][i] %= 10;
        }

        if (f[k][len + 1] > 0) len++;
    }

}

int main() {
    cin >> n;
    len = 1;
    f[1][1] = 1;
    f[2][1] = 2;
    for (int i = 3; i <= n; i++) {
        add(i);
    }

    for (int i = len; i >= 1; i--) {
        cout << f[n][i];
    }
    return 0;
}