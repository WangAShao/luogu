#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e3 + 10;
const int MAXM = 6e3 + 10;
int n, m, cnt, head[MAXN];
long long dis[MAXN];

struct Edge {
    int to;
    int w;
    int nxt;
} e[MAXM];

void addEdge (int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    e[cnt].w = w;
    head[u] = cnt;
}

int main() {
    //不会了
}