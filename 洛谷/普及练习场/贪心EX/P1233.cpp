#include <bits/stdc++.h>

using namespace std;
struct stick {
    int l, w;
} a[5010];

int n;
int ans;
int f[5010];

bool cmp (stick a, stick b) {
    if (a.l != b.l) return a.l > b.l;
    else return a.w > b.w;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].w;
    }

    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= 5000; i++) {
        f[i] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i].w > a[j].w) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
}