#include <bits/stdc++.h>

using namespace std;
int n, ans = INT_MAX;
int a[200010], fa[200010], dis[200010]; //dis数组记录到祖先节点的距离, fa数组记录它的父亲节点, 并会更新为它的祖先节点
//对于i将信息传给a[i], 那么就有一条由a[i]指向i的箭头, 由此构造出一个图, 按此种构造, 每个点入度不会超过1

int getfa(int u) {
    //找到祖先的函数
    //该函数返回祖先, 因为该函数用到了路径压缩算法
    if (fa[u] == u) return u;
    int tmpFa = fa[u]; //注意这里的一个坑, 当两个不同的连通分量合并时, 要先找到单个连通分量的祖先, 并将其保存在一个变量中
    fa[u] = getfa(fa[u]); //这里的赋值是u所在得连通分量的祖先入赘的操作
    dis[u] = dis[u] + dis[tmpFa]; // u到祖先的距离是u到之前连通分量的祖先的距离加上之前的祖先到新祖先的距离
    return fa[u];
}

void my_union(int u, int v) {
    //调用函数, 获得祖先
    int fu = getfa(u);
    int fv = getfa(v);

    if (fu == fv) {
        //这里就说明找到了环, 注意: 找到了环之后就不能连起来, 只是更新答案而已
        ans = min(ans, dis[v] + 1);
    } else {
        //若没有找到环, 那么更新祖先和距离
        fa[u] = fv;
        dis[u] = dis[v] + 1;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        //并查集的初始化
        fa[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        my_union(i, a[i]);
    }

    cout << ans;
    return 0;
}