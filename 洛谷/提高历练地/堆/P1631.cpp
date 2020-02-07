#include <bits/stdc++.h>

using namespace std;
int n, cnt;
const int MAXN = 100000 + 10;
int a[MAXN], b[MAXN];

struct Node {
    int i;
    int j;
    int val;
    bool operator <(const Node& b) const {
        return val > b.val;
    }
};

priority_queue <Node, vector<Node> > q; //小根堆

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        q.push(Node {i, 1, a[i] + b[1]});
    }

    while (cnt < n) {
        Node t = q.top();
        q.pop();

        cout << t.val << " ";
        int i = t.i;
        int j = t.j;
        q.push(Node{i, j + 1, a[i] + b[j + 1]});
        cnt++;
    }

    return 0;
}