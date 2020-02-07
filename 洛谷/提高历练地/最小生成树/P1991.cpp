#include <bits/stdc++.h>


using namespace std;
const int MAXN = 500 + 10;
const double eps = 0.0001;
int n, m, cnt, num; //n是哨所数量, m是卫星数量
int fa[MAXN];
double pos[MAXN][2], len[250010];
bool vis[MAXN];

struct edge {
    int u;
    int v;
    double w;
    bool operator<(const edge b) const {
        return w < b.w;
    } 
} e[250010];

double dis (int i, int j) {
     return sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
}

int find (int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

bool judge (double v) {
    int bound = (upper_bound(len + 1, len + 1 + cnt, v) - len) - 1;//找到最大的满足<=v的哨所
    num = 0;
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= bound; i++) {
        int u = e[i].u;
        int v = e[i].v;
        int fu = find(u);
        int fv = find(v);

        if (fu != fv) {
            fa[fu] = fv;
        }
    }
    //计算连通块的数量
    for (int i = 1; i <= n; i++) {
        int tempFa = find(i);
        if (!vis[tempFa]) {
            vis[tempFa] = true;
            num++;
        }
    }

    //只有一个连通块
    if (num == 1) {
        return true;
    }

    return (m >= num);
}

int main() {
    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf",&pos[i][0],&pos[i][1]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            e[++cnt].u = i;
            e[cnt].v = j;
            e[cnt].w = dis(i, j);
        }
    }

    sort (e + 1, e + 1 + cnt);

    for (int i = 1; i <= cnt; i++) {
        len[i] = e[i].w;
    }

    double l = 0.0, r = 100000000.0, mid;
    while ((r - l) > eps) {
        mid = (l + r) / 2;

        if (judge(mid)) {
            r = mid;
        } else {
            l = mid + eps;
        }
    }

    printf("%.2lf", mid);
    return 0;
}