#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000000 + 10;

char s[MAXN], p[MAXN];//p是模式串
int kmp[MAXN], lens, lenp;

//获得kmp数组的函数
void getkmp () {
    kmp[0] = -1;
    int k = -1;
    int j = 0;
    while (j <= lenp - 1) {
        //p[k]表示前缀, p[j]表示后缀
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            kmp[j] = k;
        } else {
            k = kmp[k];
        }
    }
}

void kmpSearch () {
    int i = 0;
    int j = 0;

    while (i < lens) {
        //j == -1就代表第一位就不匹配, 这时直接后移一位
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = kmp[j];
        }

        if (j == lenp) {
            cout << i - j + 1 << endl;
            j = kmp[j - 1];
            i--;
        }
    }
}

int main() {
    cin >> s >> p;
    lens = strlen(s);
    lenp = strlen(p);

    getkmp();
    kmpSearch();

    
    for (int i = 1; i <= lenp; i++) {
        cout << kmp[i] << " ";
    }
    return 0;
}