#include <bits/stdc++.h>

using namespace std;
int n, k;
long long ans;
const int MAXN = 5 * 1e5 + 10;
bool vis[MAXN];

struct Hole {
    int val;
    int l;
    int r;
} p[MAXN];  

struct Tree {
    int val;
    int id;

    bool operator <(const Tree& a) const {
        return val < a.val;
    }
};

priority_queue <Tree> q;

void Del (int x) {
    p[x].l = p[p[x].l].l;
    p[x].r = p[p[x].r].r;
    p[p[x].l].r = x;
    p[p[x].r].l = x;
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].val;
        p[i].l = i - 1;
        p[i].r = i + 1;
        q.push(Tree {p[i].val, i});
    }

    for (int i = 1; i <= k; i++) {
        while (vis[q.top().id]) {
            q.pop();
        }

        Tree now = q.top();
        q.pop();

        if (now.val < 0) {
            break;
        }

        ans +=  now.val;
        vis[p[now.id].l] = vis[p[now.id].r] = 1;
        p[now.id].val = p[p[now.id].l].val + p[p[now.id].r].val - p[now.id].val;
        q.push(Tree {p[now.id].val, now.id});
        Del(now.id);
    }

    cout << ans;
    return 0;
}