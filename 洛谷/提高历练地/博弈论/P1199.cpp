#include <bits/stdc++.h>

using namespace std;
int n;
int a[510][510];

int main() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sort(a[i] + 1, a[i] + 1 + n);
        if (a[i][n - 1] > ans) {
            ans = a[i][n - 1];
        }
    }

    cout << 1 << endl << ans;
    return 0;
}