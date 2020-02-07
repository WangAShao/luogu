#include <bits/stdc++.h>

using namespace std;

int a[100010];
int N, k;
int ans;

int main() {
    a[0] = a[1] = 1;

    cin >> N >> k;

    for (int i = 2; i <= N; i++) {
        for (int j = min(i, k); j >= 1; j--) {
            a[i] += a[i - j]; //这是加上第一步跨不同步数的数量
            if (a[i] >= 100003) a[i] %= 100003;
        }
    }

    cout << a[N];
    return 0;
}