#include <bits/stdc++.h>

using namespace std;
int n, a[5000001], b[5000001];
long long ans;

void merse_sort (int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        //该区间只有一个元素, 那么它一定是有序的
        return;
    } else {
        //对两边递归调用
        merse_sort(l, mid);
        merse_sort(mid + 1, r);
    }

    int i = l;
    int j = mid + 1;
    int t = l;

    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            ans += mid - i + 1; //这里即说明出现了逆序对, 仔细体会
            b[t++] = a[j];
            ++j;
        } else {
            b[t++] = a[i];
            ++i;
        }
    }

    while (i <= mid) {
        b[t++] = a[i];
        ++i;
    }

    while (j <= r) {
        b[t++] = a[j];
        ++j;
    }

    //这一步也是很重要的一步
    for(int i = l; i <= r; ++i)//把有序序列b赋值到a里 
    {
        a[i] = b[i];
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    merse_sort(1, n);
    cout << ans;
    return 0;
}