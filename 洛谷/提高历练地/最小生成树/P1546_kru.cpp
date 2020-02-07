#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100 + 10;
int n, cnt, fa[MAXN], sum, ans;

void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

int find (int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void union_(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    fa[fx] = fy;
}

struct Edge {
    int u;
    int v;
    int w;
} e[100010];


bool cmp (Edge a, Edge b) {
    return a.w < b.w;
}
//这一题应该采用并查集来判断是否会构成一个环, 然后用一个结构体数组来存储边的信息
int main() {
    cin >> n;

    init();

    int h;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> h;
            if (j > i) {
                //存一半就可以了
                e[++cnt].u = i;
                e[cnt].v = j;
                e[cnt].w = h;
            }
        }
    }

    sort(e + 1, e + 1 + cnt, cmp);

    for (int i = 1; i <= cnt; i++) {
        int u = e[i].u;
        int v = e[i].v;
        if (find(u) != find(v)) {
            union_(u, v);
            sum++;
            ans += e[i].w;

            if (sum == n - 1) {
                break;
            }
        }
    }

    cout << ans;
    return 0;
}