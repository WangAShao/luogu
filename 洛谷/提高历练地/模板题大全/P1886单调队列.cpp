#include <bits/stdc++.h>

using namespace std;

struct monotoneQueue {
    static const int MAXN = 1e6 + 10;
    int n, k, head, tail;
    int q[MAXN], p[MAXN], a[MAXN];

    void read() {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
    }

    void p_min () {
        head = 1;
        tail = 0;
        for (int i = 1; i <= n; i++) {
            //a[i]代表当前要处理的值
            while (head <= tail && q[tail] >= a[i]) {
                //如果队列末尾的元素比当前要入队的元素还要大, 那么q[tail]是不会被输出的
                tail--; //故它还是出队吧
            }

            q[++tail] = a[i]; //新元素肯定会入队, 应为如果它后面的K - 1个元素比它大的话, 它是有机会输出的
            p[tail] = i;
            //判断队首元素是否过期
            while (p[head] <= i - k) {
                head++;
            }

            if (i >= k) {
                cout << q[head] << " "; //输出最值, 队首元素一定是最值
            }
        }
        cout << endl;
    }

    void p_max () {
        head = 1;
        tail = 0;
        for (int i = 1; i <= n; i++) {
            while (head <= tail && q[tail] <= a[i]) {
                tail--;
            }

            q[++tail] = a[i];
            p[tail] = i;
            while (p[head] <= i - k) {
                head++;
            }

            if (i >= k) {
                cout << q[head] << " ";
            }
        }
        cout << endl;
    }
} worker;

int main() {
    worker.read();
    worker.p_min();
    worker.p_max();
    return 0;
}