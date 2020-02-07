#include <bits/stdc++.h>

using namespace std;
int n;
const int MAXN = 10000 + 10;
typedef unsigned long long ull;
ull base = 131;
ull a[MAXN];
char s[MAXN];
int ans = 1;

ull hash_(char s[]) {
    int len = strlen(s);
    ull ans = 0;
    for (int i = 0; i < len; i++) {
        ans = ans * base + (ull)s[i]; //溢出时会自动的对2^64取模, 故这里可以偷懒一波
    }

    return ans & 0x7fffffff; //表示对ans取正
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        a[i] = hash_(s);
    }

    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}