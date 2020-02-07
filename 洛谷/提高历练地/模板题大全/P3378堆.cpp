#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000000 + 10;

int n, option, heap[MAXN], heap_size;

void swap_(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

void push (int x) {
    heap[++heap_size] = x; //先放到堆底
    int now = heap_size;
    while (now > 1) {
        int fa = now >> 1; //找到父亲节点
        if (heap[now] < heap[fa]) {
            swap(heap[now], heap[fa]);
        } else {
            break;
        }

        now = fa;
    }
    return ;
}

void pop () {
    swap(heap[heap_size--], heap[1]);
    heap[heap_size + 1] = 0;
    
    int now = 1;
    while (now << 1 <= heap_size) {
        int left = now << 1;
        if (left + 1 <= heap_size && heap[left] > heap[left + 1]) {
            left++;
        }

        if (heap[left] < heap[now]) {
            swap(heap[left], heap[now]);
        } else {
            break;
        }

        now = left;
    }
}

int main() {
    cin >> n;

    int x;
    while(n--) {
        cin >> option;
        switch (option) {
            case 1:
                cin >> x;
                push(x);
                break;
            case 2:
                cout << heap[1] << endl;
                break;
            case 3:
                pop();
                break;
            default:
                break;
        }
    }

    return 0;
}