#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAXN = 100 + 10;
const int mod = 1e9 +7;
int n;
ll k;

struct Mat {
    ll m[MAXN][MAXN];
    Mat() {
        memset(m, 0, sizeof(m));
    }
    void build () {
        for (int i = 1; i <= n; i++) {
            m[i][i] = 1;
        }
    }
} mat, ans;

Mat operator* (const Mat& a, const Mat& b) {
    Mat c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                c.m[i][j] = c.m[i][j] % mod + a.m[i][k] * b.m[k][j] % mod;
            }
        }
    }

    return c;
}

int main() {
    cin >> n >> k;
    ans.build(); //ans初始化为单位矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat.m[i][j];
        }
    }

    while (k > 0) {
        if (k & 1) {
            ans = ans * mat;
        }
        mat = mat * mat;
        k >>= 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans.m[i][j] % mod << " ";
        }
        cout << endl;
    }

    return 0;
}