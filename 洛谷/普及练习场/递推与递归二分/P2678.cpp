#include <bits/stdc++.h>
#define maxn 500010
using namespace std;

int l, r, n, m, ans, mid, d;
int a[maxn];

bool judge(int x) {
    int tot = 0;
    int i = 0;
    int now = 0;

    while(i < n + 1) {
        i++;
        if (a[i] - a[now] < x) {
            //那么就将这块石头拿走
            tot++;
        } else {
            now = i;
        }
    }
    if (tot > m) {
        return false;
    } else {
        return true;
    }
}

int main() {
    cin >> d >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[n + 1] = d;

    l = 1, r = d;
    while (l <= r) {
        mid = (l + r) / 2;
        if (judge(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}