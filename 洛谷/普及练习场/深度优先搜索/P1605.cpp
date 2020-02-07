#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;

int map_[maxn][maxn];
int vis[maxn][maxn];

int dx[4]={0,0,1,-1};//打表；
int dy[4]={-1,1,0,0};//打表；
int n, m, t, total = 0;
int startx, starty, endx, endy;

void walk (int x, int y) {
    if (x == endx && y == endy) {
        total++;
        return;
    } else {
        for (int i = 0; i < 4; i++) {
            //判断边界条件
            if(x + dx[i] >= 1 && x + dx[i] <= m && y + dy[i] >= 1 && y + dy[i] <= n) {
                //判断有没有障碍物
                if (vis[x + dx[i]][y + dy[i]] == 0 && map_[x + dx[i]][y + dy[i]] == 0) {
                    vis[x][y] = 1;
                    walk(x + dx[i], y + dy[i]);
                    //回溯时记得擦除状态
                    vis[x][y] = 0;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;
    cin >> startx >> starty >> endx >> endy;

    memset(map_, 0, maxn);
    memset(vis, 0, maxn);
    //如果有障碍的, 那么在地图上面将其标记为1
    int x, y;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        map_[x][y] = 1;
    }
    walk(startx, starty);
    cout << total << endl;
    return 0;
}