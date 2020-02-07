//打算尝试一下Dijkstra算法的链式前向星写法以及堆优化

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pa;
int n, m, s, t, head[10000], cnt, dis[10000];

//建立边结构体,其中edge[i].to表示第i条边的终点,edge[i].next表示与第i条边同起点的下一条边的存储位置,edge[i].w为边权值.
struct Edge {
    int next;
    int to;
    int w;
} e[100000]; //这里至少要开双倍那么大, 因为是无向图, 双向都要加边哒

struct cmp
{
    bool operator()(const pa p1, const pa p2)
    {
        return p1.second > p2.second; //second的小值优先
    }
};


void addEdge(int u, int v, int w) {
    e[++cnt].w = w;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt; //head[i]保存的是以i为起点的所有边中编号最大的那个,而把这个当作顶点i的第一条起始边的位置.
}

void dijkstra () {
    priority_queue <pa, vector<pa>, cmp > q;

    q.push(make_pair(s, 0)); //将源点放入优先队列

    for (int i = 1; i <= n; i++) {
        dis[i] = 2e9;
    }
    dis[s] = 0;

    while (!q.empty()) {
        int now = q.top().first;
        int val = q.top().second;

        q.pop();
        for (int i = head[now]; i; i = e[i].next) {
            int to = e[i].to;

            if (dis[to] > e[i].w + val) {
                dis[to] = e[i].w + val;
                q.push(make_pair(to, dis[to]));
            }
        }
    }

}

int main() {
    cin >> n >> m >> s >> t;

    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    dijkstra();

    cout << dis[t];
    return 0;
}