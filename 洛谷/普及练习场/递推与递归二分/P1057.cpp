#include <bits/stdc++.h>

using namespace std;
int f[31][31], n, m;

void dfs(int s, int c) {
    f[s][c] = 0;
    if (c == m && s == 1) f[s][c] = 1;
    if (c != m) {
        //没搜到上限, 那么继续进行搜索
        if (f[s % n + 1][c + 1] == -1) {
            //说明右边没有记忆
            dfs(s % n + 1, c + 1);
        }

        if (f[s != 1 ? s - 1 : n][c + 1] == -1) {
            //说明左边没有记忆
            dfs(s != 1 ? s - 1 : n, c + 1);
        }

        f[s][c] = f[s % n + 1][c + 1] + f[s != 1 ? s - 1 : n][c + 1];
    }
} 

int main() {
    memset(f, -1, sizeof(f));
    cin >> n >> m;
    dfs(1, 0);
    cout << f[1][0];
    return 0;
}