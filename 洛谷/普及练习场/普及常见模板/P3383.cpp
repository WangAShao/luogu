#include <bits/stdc++.h>

const int MAXN = 10000010;
using namespace std;

int n, m;
bool prime[MAXN];

void make_prime (int n) {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (prime[i]) {
            for (int j = i + i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(prime, true, sizeof(prime));
    make_prime(n);

    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        if (prime[k]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}