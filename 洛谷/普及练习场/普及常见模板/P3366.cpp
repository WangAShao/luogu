#include <bits/stdc++.h>
#define MAXN 1
using namespace std;

int n, m, u, v, total;
bool marked[MAXN]; //同来判断顶点是否在树中的一个布尔数组

struct Edge {
    long long weight;
    int start;
    int to;
} edge[2000005];

int f[100000];
long long ans;

int find(int x) {
    //并查集, 用于判断两个顶点是否在同一颗树中
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

bool cmp(Edge a, Edge b) {
    //sort函数使用
    return a.weight < b.weight;
}

inline void kruskal() {
    for (int i = 1; i <= m; i++) {
        u = find(edge[i].start);
        v = find(edge[i].to);
        if (u == v) {
            //说明在同一颗树中
            continue;
        }

        //否则说明加上这条边并不会构成一个环
        ans += edge[i].weight;
        //连接两个并查集
        f[u] = v;
        total++;
        if (total == n - 1) {
            break;
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin >> edge[i].start >> edge[i].to >> edge[i].weight;
    }

    sort(edge + 1, edge + 1 + m, cmp);

    kruskal();
    cout << ans;
    return 0;

}