#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long 

using namespace std;

struct node {
    ll num[5][5];
} e, g1, g2;

node operator* (const node& a, const node& b) {
    node ans;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            ans.num[i][j] = 0;
            for (int k = 1; k <= 3; k++) {
                ans.num[i][j] = (ans.num[i][j] % mod + a.num[i][k] * b.num[k][j] % mod) % mod;
            }
        }
    }

    return ans;
}

//位运算
node power_ (node a, int y) {
    node ans = e;
    while (y) {
        if (y & 1) {
            ans = ans * a;
        }
        a = a * a;
        y >>= 1;
    }
    return ans;
}

int main() {
    int n, t;
    //初始化
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            e.num[i][j] = (i == j);
            g1.num[i][j] = g2.num[i][j] = 0;
        }
    }

    g2.num[1][1] = g2.num[1][2] = g2.num[2][3] = g2.num[3][1] = 1;
    g1.num[1][1] = g1.num[1][2] = g1.num[1][3] = 1;

    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 3) {
            cout << 1 << endl;
            continue;
        }

        node ans = g1 * power_(g2, n - 3);
        cout << ans.num[1][1] << endl;
    }
    return 0;
}