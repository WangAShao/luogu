#include <bits/stdc++.h>

using namespace std;
int n, m;
const int MAXN = 1000000 + 10;
const int MAXM = 1000000000;
int h[MAXN];
long long sum;
int ans;

bool judge (int x) {
    sum = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] > x) {
            sum += h[i] - x;
        }
    }

    if (sum >= m) return true;
    else return false;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    int l = 1;
    int r = MAXM;
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (judge(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}   