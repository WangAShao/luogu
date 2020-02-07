#include <bits/stdc++.h>

using namespace std;

char map_[1001][1001];
int vis[1001][1001], a[1000001];

struct point {
    int x, y;
} p[1000001];

int connectCompnent;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};//四个方向
int cur, queue_len, sum, nx, ny;
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map_[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                //如果该点没有访问过, 那么就对该点所在的连通分量进行搜索
                connectCompnent++;
                cur = 1;
                queue_len = 1;
                p[cur].x = i;
                p[cur].y = j;
                vis[i][j] = connectCompnent;
                sum = 1;
                while (cur <= queue_len) {
                    for (int k = 0; k < 4; k++) {
                        nx = p[cur].x + dx[k];
                        ny = p[cur].y + dy[k];
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && map_[p[cur].x][p[cur].y] != map_[nx][ny] && !vis[nx][ny]) {
                            queue_len++;
                            sum++;
                            vis[nx][ny] = connectCompnent;
                            p[queue_len].x = nx;
                            p[queue_len].y = ny;
                        }
                    }
                    //搜索队列中的下一个点
                    cur++;
                }
                //保存该编号的连通分量可以移动多少格
                a[connectCompnent] = sum;
            }
        }
    }

    for(int i=1;i<=m;i++)
    {
        int sx, sy;
        cin>>sx>>sy;//读入询问 
        cout<<a[vis[sx][sy]]<<endl;//直接查找答案并输出 
    }
    return 0;
}