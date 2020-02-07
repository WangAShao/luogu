#include <bits/stdc++.h>

using namespace std;
int n;
int up[110], down[110], a[110];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        up[i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            if (a[i] > a[j]) {
                up[i] = max(up[i], up[j] + 1);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        down[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) {
                down[i] = max(down[i], down[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, up[i] + down[i] - 1);
    }

    cout << n - ans;
    return 0;
}