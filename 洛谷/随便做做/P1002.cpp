#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int MAXN = 30;
int x, y, n, m;
const int fx[]={0,-2,-1,1,2,2,1,-1,-2};
const int fy[]={0,1,2,2,1,-1,-2,-2,-1};
bool obstacle[MAXN][MAXN];
ull f[MAXN][MAXN];

int main() {
    cin >> n >> m >> x >> y;
    ++n, ++m, ++x, ++y;
    f[1][1] = 1;
    obstacle[x][y] = 1;
    for (int i = 1; i <= 8; i++) {
        obstacle[x + fx[i]][y + fy[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (obstacle[i][j]) {
                continue;
            }
            f[i][j] = max(f[i][j], f[i - 1][j] + f[i][j - 1]);
        }
    }
    //f[i][j]代表到map_[i][j]有多少条路
    cout << f[n][m] << endl;
    return 0;
}