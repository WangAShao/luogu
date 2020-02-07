#include <bits/stdc++.h>

using namespace std;

//这一题看了神犇们的解法, 发现还是string更简单
string a[20];

int cmp (string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
}