#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10000 + 10;
int n, map_[MAXN][MAXN], ans, indgree[MAXN];
char res[MAXN]; //indgree是存放每个顶点的入度的

void solve(int i) {
    for (int j = 1; j <= 150; j++) {
        if (map_[i][j] > 0) {
            map_[i][j]--;
            map_[j][i]--;
            solve(j);
        }
    }
    res[++ans] = i;
    return;
}

void printRes() {
    for (int k = ans; k >= 1; k--) {
        cout << res[k];
    }
    cout << endl;
}

int main() {
    cin >> n;
    //对输入数据进行处理
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        map_[s[0]][s[1]] = 1;
        map_[s[1]][s[0]] = 1;
        indgree[s[0]]++;
        indgree[s[1]]++;
    }

    //接下来判断是否存在欧拉路径或者欧拉回路
    int cnt = 0, flag = 0;
    for (int i = 1; i <= 150; i++) {
        if (indgree[i] & 1) {
            //出现了奇数度数的点
            cnt++;
            if (!flag) {
                flag = i;
            }
        }
    }

    if (cnt && cnt != 2) {
        cout << "No Solution";
        return 0;
    }

    if (!flag) {
        for (int i = 1; i <= 150; i++) {
            if (indgree[i]) {
                flag = i;
                break;
            }
        }
    }

    //以flag的值所对应的点开始寻找欧拉回路或者欧拉路径
    solve(flag);

    if (ans != n + 1) {
        cout << "No Solution";
        return 0;
    }

    printRes();
    return 0;
}