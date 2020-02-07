#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5 * 10e4 + 10;
int n, k, ans;
int fa[MAXN * 3];

int find (int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unity (int x, int y) {
    int fx = find(x);
    int fy = find(y);

    fa[fx] = fy;
}

int main() {
    cin >> n >> k;

    //并查集的初始化
    for (int i = 1; i <= n; i++) { //对于每种生物：设 x 为本身，x+n 为猎物，x+2*n 为天敌
        fa[i] = i;
        fa[i + n] = i + n;
        fa[i + n + n] = i + n + n; 
    }

    int option, animal1, animal2;
    for (int i = 1; i <= k; i++) {
        cin >> option >> animal1 >> animal2;
        if (animal1 > n || animal2 > n) {
            ans++;
            continue;
        }

        if (option == 2 && animal1 == animal2) {
            ans++;
            continue;
        }

        if (option == 1) {
            if (find(animal1 + n) == find(animal2) || find(animal1 + n + n) == find(animal2)) {
                //animal1 + n代表animal1的猎物, 故第一条判断语句代表animal2 与 animal1的猎物是同类, 即animal2是animal1的猎物
                ans++;
                continue;
            }

            unity(animal1, animal2);unity (animal1 + n, animal2 + n); unity(animal1 + n + n, animal2 + n + n);
        } else if (option == 2){
            if (find (animal1) == find (animal2) || find (animal1 + n + n) == find (animal2)) {
                ans++;
                continue;
            }
            unity(animal1, animal2 + n + n); unity (animal1 + n, animal2); unity (animal1 + n + n, animal2 + n); 
        }
    }

    cout << ans;
    return 0;
}