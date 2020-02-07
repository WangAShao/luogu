#include <bits/stdc++.h>

using namespace std;
int a[100010], up[100010], down[100010];
int ans1, ans2, n = 1;

int main() {
    while (scanf("%d", &a[n]) != EOF) n++;
    n--;

    for (int i = 1; i <= n; i++) {
        up[i] = down[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            //对于求最长不升序列的长度, 注意down[i]代表从1到i的最长不升序列的长度
            if (a[i] <= a[j]) {
                down[i] = max(down[i], down[j] + 1);
            } else {
            //这里就是求最长上升序列的长度, 注意up[i]代表从1到i的最长上升序列的长度
                up[i] = max(up[i], up[j] + 1);
            }
            ans1 = max(ans1, down[i]);
            ans2 = max(ans2, up[i]);
        }
    }

    cout << ans1 << endl << ans2;
    return 0;
}