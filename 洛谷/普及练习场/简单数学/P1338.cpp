#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool flag;
//这道题目确实是我想错了, 如果第i个数不能放在第i位, 那么应放在越后面越好, 这样放在第i位的数会更小, 这个数也会更小
ll n, m, a[50010], pos, i;
int main() {
    cin >> n >>m;

    ll head = 1;
    ll tail = n;
    ll sum;

    for (int i = 1; i <= n; i++) {
        sum = (ll) (n - i) * ( n - i - 1) / 2;
        if (sum >= m) {
            a[head++] = i;
        } else {
            a[tail--] = i;
            m -= (tail - head + 1);
        }
    } 

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}