#include <bits/stdc++.h>

using namespace std;
const int MAXN = 190003;
const int MAXM = 1e5 + 10;

int head[MAXN], low[MAXN], dfn[MAXN], stack_[MAXN], exist[MAXN], color[MAXN], num[MAXN], outDgree[MAXN];
int n, m, cnt, tot, top, id, ans;

//链式前向星
struct Cow {
    int to;
    int nxt;
} cow[MAXM];

//加边
void addEdge (int u, int v) {
    cow[++cnt].to = v;
    cow[cnt].nxt = head[u];
    head[u] = cnt;
}

void dfs(int x) {
    dfn[x] = low[x] = ++tot; //都初始化为x
    stack_[++top] = x; //点x入栈
    exist[x] = 1; //表示点x在栈中
    for (int i = head[x]; i; i = cow[i].nxt) {
        if (!dfn[cow[i].to]) {
            //如果与它相连的这个点还没有被遍历
            dfs(cow[i].to);
            low[x] = min(low[x], low[cow[i].to]);
        } else if (exist[cow[i].to]) {
            //如果与它相连的这个点在栈中, 表示它们在同一个连通分量中
            low[x] = min(low[x], low[cow[i].to]);
        }
    }//end for

    if (low[x] == dfn[x]) {
        //如果节点x是强连通分量的根
        id++; //每个连通分量的标号
        do {
            color[stack_[top]] = id;
            num[id]++;
            exist[stack_[top]] = 0;
        } while (x != stack_[top--]);
    }
}

int main() {
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b; //代表a喜欢b, 就有一条从a指向b的边
        addEdge(a, b);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = cow[j].nxt) {
            if (color[i] != color[cow[j].to]) {
                outDgree[color[i]]++;
            }
        }
    }

    for (int i = 1; i <= id; i++) {
        if (outDgree[i] == 0) {
            if (ans) {
                cout << 0;
                return 0;
            }
            ans = i;
        }
    }

    cout << num[ans];
    return 0;
}