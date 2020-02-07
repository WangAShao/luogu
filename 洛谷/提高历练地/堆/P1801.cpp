#include <bits/stdc++.h>

using namespace std;
priority_queue <int> Qmax; //大根堆
priority_queue <int, vector<int>, greater<int> > Qmin; //小根堆
int n, m;
const int MAXN = 200000 + 10;
int a[MAXN], b[MAXN];

int main() {
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int c, t;
    for (int i = 1, j = 1; i <= n; i++) {
        for (; j <= b[i]; j++) {
            Qmin.push(a[j]);
        }
        c = Qmin.top();
        Qmin.pop();
        Qmax.push(c);
        while (Qmin.size() > 0 && Qmin.top() < Qmax.top()) {
            t = Qmax.top();
            Qmax.pop();
            c = Qmin.top();
            Qmin.pop();
            Qmax.push(c);
            Qmin.push(t);
        }
        cout << Qmax.top() << endl;
    }
    return 0;
}