#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100000 + 10;
int n, next_[MAXN];
int color[MAXN], dfn[MAXN], c_size[MAXN], sucdfn[MAXN];//c_size[i]代表第i头牛的路线中环的大小, sucdfn[i]代表第i头牛的入环时间戳

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> next_[i];
    }

    for (int cow = 1; cow <= n; cow++) {
        for (int i = cow, cnt = 0; ; i = next_[i], cnt++) {
            if (!color[i]) {
                color[i] = cow;
                dfn[i] = cnt;
            } else if (color[i] == cow) {
                c_size[cow] = cnt - dfn[i];
                sucdfn[cow] = dfn[i];
                cout << cnt << endl;
                break;
            } else {
                c_size[cow] = c_size[color[i]];
                sucdfn[cow] = cnt + max(0, sucdfn[color[i]] - dfn[i]);
                cout << sucdfn[cow] + c_size[cow] << endl;
                break;
            }
        }
    }

    return 0;
}