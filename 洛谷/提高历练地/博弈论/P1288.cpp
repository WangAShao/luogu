#include <bits/stdc++.h>

using namespace std;
int a[30], n;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 99, r = -1;

    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    l--;
    r = n - r;

    if (l & 1 || r & 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}