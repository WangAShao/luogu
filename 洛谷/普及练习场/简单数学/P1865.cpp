#include <bits/stdc++.h>

using namespace std;
int n, m;
const int MAXN = 1000010;
bool prime[MAXN];
int f[MAXN]; //用来保存前缀和

void make_prime(int m) {
    memset(prime, true, sizeof(prime));

    prime[0] = prime[1] = false;

    for (register int i = 2; i <= m; i++) {
        if (prime[i]) {
            f[i] = f[i - 1] + 1;
            for (register int j = 2 * i; j <= m; j += i) {
                prime[j] = false;
            }   
        } else {
            f[i] = f[i - 1]; //前缀和转移
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    make_prime(m);
    int l, r, count;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;

        if (l < 1 || r > m || l > r) {
            cout << "Crossing the line" << endl;
        } else {
            int y = f[r] - f[l - 1];
            cout << y << endl;
        }  
    }

    return 0;
}