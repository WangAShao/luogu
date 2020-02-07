#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10010;
int n, indgree[MAXN], len[MAXN], dp[MAXN], ans; //indgree数组维护的是每一个点的入度
vector <int> relyOn[MAXN]; //第i个存依赖于任务i的任务向量
queue <int> q; //存放入度为0, 即前导依赖任务都完成了的任务

void topoSort() {
    for (int i = 1; i <= n; i++) {
        if (indgree[i] == 0) {
            q.push(i);
            dp[i] = len[i];
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < relyOn[now].size(); i++) {
            int nex = relyOn[now][i];

            dp[nex] = max(dp[nex], dp[now] + len[nex]);
            indgree[nex]--;
            if (indgree[nex] == 0) {
                q.push(nex);
            }
        }
    }
}

int main() {
    cin >> n;

    int id, e;
    for (int i = 1; i <= n; i++) {
        cin >> id;
        cin >> len[id];
        while (cin >> e && e) {
            relyOn[e].push_back(id);
            indgree[id]++;
        }
    }

    topoSort();

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}