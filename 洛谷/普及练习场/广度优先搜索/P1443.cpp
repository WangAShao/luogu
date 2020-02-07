#include <bits/stdc++.h>

using namespace std;

int map_[401][401];
bool vis[401][401];
//8个方位
int dirx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int diry[8] = {2, -2, 1, -1, 2, -2, 1, -1};

struct point {
    int x, y;
} node, top;

int dx, dy;
queue<point> q;
int n, m;
void bfs(int x, int y, int step) {
    map_[x][y] = step;
    vis[x][y] = true;
    node.x = x;
    node.y = y;
    q.push(node);
    while(!q.empty()) {
        top = q.front();
        q.pop();

        for (int k = 0; k < 8; k++) {
            dx = top.x + dirx[k];
            dy = top.y + diry[k];
            if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && vis[dx][dy] == false) {
                node.x = dx, node.y = dy;
                q.push(node);
                vis[dx][dy] = true; //标记已经入队过
                map_[dx][dy] = map_[top.x][top.y] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int startx, starty;
    cin >> startx >> starty;

    memset(map_, -1, sizeof(map_));
    memset(vis, false, sizeof(vis));

    bfs(startx, starty, 0);

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)
            printf("%-5d", map_[i][j]);//注意场宽 我在这被卡了两次= =
        printf("\n");
    }
    return 0;
}