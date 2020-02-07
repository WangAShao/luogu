#include <bits/stdc++.h>

using namespace std;

int x, y, sum = 0;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

//关键:最大公约数和最小公倍数的乘积就是原两个数的积
int main() {
    cin >> x >> y;

    for (int i = 1; i * i <= x * y; i++) {
        if ((x * y) % i == 0 && gcd(i, (x * y) / i) == x) {
            sum++;
        }
    }

    if (x == y) cout << sum * 2 - 1;
    else cout << sum * 2 ;
    return 0;
}