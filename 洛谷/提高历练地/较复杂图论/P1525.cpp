#include <bits/stdc++.h>

using namespace std;

struct Relation {
    int p1;
    int p2;
    int w;
} p[100010];
int n, m, l, r, mid, ans;
int fa[20010 << 1];
bool cmp (const Relation& a, const Relation b) {
    return a.w > b.w;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}



int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> p[i].p1 >> p[i].p2 >> p[i].w;
    }

    sort(p + 1, p + 1 + m, cmp);

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        fa[i + n] = i + n;
    }

    for (int i = 1; i <= m; i++) {
        int p1 = p[i].p1;
        int p2 = p[i].p2;

        if (find(p1) == find(p2) || find(p1 + n) == find(p2 + n)) {
            ans = p[i].w;
            break;
        }

        fa[fa[p1 + n]] = fa[p2];
        fa[fa[p1]] = fa[p2 + n];
    }

    cout << ans << endl;
    return 0;
}