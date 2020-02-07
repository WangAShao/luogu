//如果染色过后那个地方还是0, 那么就说明那个地方没有扫到, 说明它被墙围住了
//技巧:在外面再加一圈墙

#include <bits/stdc++.h>

using namespace std;

int m[35][35], vis[35][35];
int n;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

void dfs (int x, int y) {
    if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || vis[x][y] != 0) {
        return;
    } 
    //否则
    vis[x][y] = 1; //对这一点进行访问(染色)
    for(int i = 1; i <= 4; i++) {
        dfs(x + dx[i], y + dy[i]);
    }

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> m[i][j];
            if (m[i][j]) 
                vis[i][j] = 2;
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j] == 0) {
                cout << 2 << ' ';
            } else if (vis[i][j] == 2) {
                    cout << 1 << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << endl;
    }
}