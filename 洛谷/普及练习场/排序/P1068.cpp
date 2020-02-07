#include <bits/stdc++.h>
using namespace std;

int i, n, m, f, k[5001], s[5001], sub[5001];
bool cmp (int a, int b) {
    if (s[a] == s[b]) return k[a] < k[b];//成绩相等则比编号
    return s[a] > s[b];// 否则比成绩
}

int main () {
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> k[sub[i] = i] >> s[i]; //输入编号和成绩, 顺便初始化下标
    }
    sort(sub + 1, sub + n + 1, cmp);
    f = s[sub[int(m * 1.5)]];
    for (i = 1; s[sub[i]] >= f; i++) {
    }
    cout<<f<<" "<<i - 1<<endl;
    for (i = 1; s[sub[i]] >= f; i++) {
        cout << k[sub[i]] << " " << s[sub[i]] << endl;
    }
}