#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int a, b;
int an[maxn];
int l, r, mid, ans;
bool judge(int x) {
    int tot = 1;
    int now = 1;
    for (int i = 2; i <= a; i++) {
        if (an[i] - an[now] >= x) {
            tot++;
            now = i;
        }
    }

    if (tot >= b) return true;
    else return false;
}

int main() {
    cin >> a >> b;

    for (int i = 1; i <= a; i++) {
        cin >> an[i];
    }

    sort(an + 1, an + 1 + a);
    l = 1;
    r = an[a] - an[1];

    while (l <= r) {
        mid = (l + r) / 2;
        if (judge(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l - 1;
}