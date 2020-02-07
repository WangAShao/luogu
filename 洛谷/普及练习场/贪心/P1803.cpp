#include <bits/stdc++.h>

using namespace std;

struct game {
    int start;
    int end;
} g[1000001];

int cmp (const game& a, const game& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> g[i].start >> g[i].end;
    }

    sort (g, g + n, cmp);
    int count = 1;
    int lastEnd = g[0].end;
    for (int i = 1; i < n; i++) {
        if (g[i].start >= lastEnd) {
            count++;
            lastEnd = g[i].end;
        }
    }

    printf("%d\n", count);
}