#include <bits/stdc++.h>

using namespace std;

int prices[30000];
int w;
int n;

int main() {
    cin >> w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    sort (prices, prices + n);

    int i = 0; int j = n - 1;
    int count = 0;
    while (i < j) {
        if (prices[i] + prices[j] <= w) {
            count++;
            i++;
            j--;
        } else {
            count++;
            j--;
        }
    }
    if (i == j) count++;
    printf("%d\n", count);
}