#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int sum;

int main() {
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    while(q.size() >= 2) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        sum += a + b;
        q.push(a + b);
    }

    cout << sum << endl;
    return 0;
}