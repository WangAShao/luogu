#include <bits/stdc++.h>

using namespace std;

int n, total;
int a[3][100], ans[100];

void print() {
    if (total <= 2) {
         for (int k = 1; k <= n; k++) {
             printf("%d ", ans[k]);
         }
         printf("\n"); 
    }
    ++total;
    return;
}

void queen(int i) {
    if (i > n) {
        print();
        return;
    } else {
        for (int j = 1; j <= n; j++) {
            if (!a[0][j] && !a[1][i + j] && !a[2][i - j + n]) {
                ans[i] = j;
                a[0][j] = 1;
                a[1][i + j] = 1;
                a[2][i - j + n] = 1;
                queen(i + 1);
                a[0][j] = 0;
                a[1][i + j] = 0;
                a[2][i - j + n] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    queen(1);
    cout << total << endl;
    return 0;
}