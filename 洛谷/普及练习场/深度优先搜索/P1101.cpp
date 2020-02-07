#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
char m[maxn][maxn], stand[] = "yizhong"; //m代表字符矩阵,stand代表标准字符串
int vis[maxn][maxn]; //这个代表染色体矩阵

struct  node
{
    int x, y;
} c[maxn]; //用于记录路径

int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};//八向的常量数组

void dfs (int x, int y, node c[], int k, int cur) {
    if (cur == 7) {
        //进入了这里就代表已经找到了一条符合的单词了, 故接下来对染色体进行染色
        for (int i = 0; i < 7; i++) {
            vis[c[i].x][c[i].y] = 1;
        }
    } else {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        //注意这里的判定条件
        if (cur == 6 || m[dx][dy] == stand[cur + 1]) {
            c[cur].x = x;
            c[cur].y = y;
            dfs(dx, dy, c, k, cur + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", m[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //首先找到 字符y
            if (m[i][j] == 'y') { 
                for (int k = 0; k < 8; k++) {
                    //然后遍历八个方向, 找到i对应的方向
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (m[x][y] == 'i') {
                        dfs(i, j, c, k, 0);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) {
                printf("%c", m[i][j]); //被染色了的, 就输出对应字符
            } else {
                printf("*"); //否则就输出*
            }
        }
        printf("\n");
    }
    return 0;
}
