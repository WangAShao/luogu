#include <bits/stdc++.h>

using namespace std;
//状态定义
int la, lb, a[110], b[110], f[110][110];
int d[6][6] = {
    {0,0,0,0,0,0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}
};

int main() {
    cin >> la;
    for (int i = 1; i <= la; i++) {
        char ch;
        cin >> ch;
        switch (ch) {
            case 'A':
                a[i] = 1; break;
            case 'C':
                a[i] = 2; break;
            case 'G':
                a[i] = 3; break;
            case 'T':
                a[i] = 4; break;    
        }
    }
    cin >> lb;
    for (int i = 1; i <= lb; i++) {
        char ch;
        cin >> ch;
        switch (ch) {
            case 'A':
                b[i] = 1; break;
            case 'C':
                b[i] = 2; break;
            case 'G':
                b[i] = 3; break;
            case 'T':
                b[i] = 4; break;    
        }
    }

    //现在开始进行边界的处理
    f[0][0]=0;//全局变量自动初始化为0，但是作为题解，还是写上好。
	for(int i=1;i<=la;i++)
		f[i][0]=f[i-1][0]+d[a[i]][5];
	for(int i=1;i<=lb;i++)
		f[0][i]=f[0][i-1]+d[5][b[i]];

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            //最后一对碱基只有以下3种可能：
            // 非空碱基和非空碱基。
            // 非空碱基和空碱基。
            // 空碱基和非空碱基。
            // 所有动态转移方程这样写
            f[i][j] = max(f[i - 1][j - 1] + d[a[i]][b[j]], max(f[i - 1][j] + d[a[i]][5], f[i][j - 1] + d[5][b[j]]));
        }
    }

    cout << f[la][lb] << endl;
    return 0;
}