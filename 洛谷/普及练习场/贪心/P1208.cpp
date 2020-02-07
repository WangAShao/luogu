#include <bits/stdc++.h>

using namespace std;

struct person {
    int unitPrice;
    int amount;
} p[5000];

bool cmp (const person& a, const person& b) {
    return a.unitPrice < b.unitPrice;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> p[i].unitPrice >> p[i].amount;
    }

    sort(p, p + m, cmp);

    int count = 0;
    int i = 0;
    while (n > 0) {
        if (p[i].amount <= n) {
            count += p[i].amount * p[i].unitPrice;
            n -= p[i].amount;
        } else {
            count += p[i].unitPrice * n;
            break;
        }
        i++;
    }

    printf("%d\n", count);
    return 0;
}