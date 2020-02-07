#include <bits/stdc++.h>

using namespace std;
char a1[50010], b1[50010];
int a[50010], b[50010], c[50010], x, len;

int main() {
    cin >> a1 >> b1;
    a[0] = strlen(a1);
    b[0] = strlen(b1);

    for (int i = 1; i <= a[0]; i++) {
        a[i] = a1[a[0] - i] - '0';
    }

    for (int i = 1; i <= b[0]; i++) {
        b[i] = b1[b[0] - i] - '0';
    }

    for (int i = 1; i <= a[0]; i++) {
        for (int j = 1; j <= b[0]; j++) {
            c[i + j - 1] += a[i] * b[j];
        }
    }

    len = a[0] + b[0];
    for (int i = 1; i < len; i++) {
        if (c[i] > 9) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }

    while (c[len] == 0 && len > 1) len--;

    for (int i = len; i > 0; i--) {
        cout << c[i];
    }

    cout << endl;
    return 0;
}