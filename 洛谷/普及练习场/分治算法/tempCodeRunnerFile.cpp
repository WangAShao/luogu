#include <bits/stdc++.h>

using namespace std;
/**
 * 求a^b 
 */
int quickPower(long long int a, long long int b, long long int k) {
    int ans = 1, base = a;

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
    long long int b, p, k;

    cin >> b >> p >> k;
    long long int result = quickPower(b, p, k);
    cout << b << "^" << p << " mod " << k << "=" << result << endl;
}