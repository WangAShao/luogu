#include <bits/stdc++.h>

using namespace std;
int n, a, b;

int find(int x, int y, int p) {
    if (x == y) {
        return p;
    }

    if (y / x >= 2) {
        return p;
    } else {
        return find(y - x, x, p ^ 1);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }

        if (find(a, b, 0) == 0) cout << "Stan wins" << endl;
        else cout << "Ollie wins" << endl;
    }

    return 0;
}