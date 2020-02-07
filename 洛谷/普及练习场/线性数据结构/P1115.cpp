#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, maxn, j, sum;
    cin >> n >> maxn;
    sum = maxn;
    while (--n) {
        cin >> j;
        sum = sum > 0 ? sum : 0;
        sum += j;
        maxn = maxn > sum ? maxn : sum;
    }

    cout << maxn;
    return 0;
}