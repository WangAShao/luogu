#include<bits/stdc++.h>

using namespace std;
int e[12], n, k;
struct person {
    int weight;
    int num;
    int category;
} p[20010];

bool cmp(const person& a, const person& b) {
    if (a.weight != b.weight) return a.weight > b.weight;
    return a.num < b.num;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 10; i++) {
        scanf("%d", &e[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].weight);
        p[i].num = i;
    }

    sort(p +1, p + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        p[i].category = (i - 1) % 10 + 1;
        p[i].weight += e[p[i].category];
    }

    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= k; i++) {
        printf("%d ", p[i].num);
    }

    return 0;
}