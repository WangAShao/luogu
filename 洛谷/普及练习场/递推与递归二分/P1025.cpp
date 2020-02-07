#include <bits/stdc++.h>

using namespace std;

int n, k, cnt;

void dfs(int last, int sum, int depth) {
    if (depth == k) {
        if (sum == n) cnt++;
        return;
    }

    for (int i = last; sum + i * (k - depth) <= n; i++) {
        dfs(i, sum + i, depth + 1);
    }
}

int main() {
    cin >> n >> k;
    dfs(1, 0, 0);
    cout << cnt;
}