#include <bits/stdc++.h>

using namespace std;
/**
 * 求a^b 
 */
long long quickPower(long long a, long long b, long long k) {
    long long ans = 1, base = a;

    if (b == 0) {
        return a % k;
    }

    while(b > 0) {
        if (b & 1) {
            ans *= base;
            ans %= k;
        }
        base *= base;
        base %= k;
        b >>= 1;
    }
    return ans;
}

int main() {
    long long b, p, k;

    cin >> b >> p >> k;
    long long result = quickPower(b, p, k);
    cout << b << "^" << p << " mod " << k << "=" << result << endl;
}