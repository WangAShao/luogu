#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, fa;
} t[30];

int n, root;
string s;

void visit(int k) {
    char ch = k + 96;
    cout << ch;
    if (t[k].l != 0) visit(t[k].l);
    if (t[k].r != 0) visit(t[k].r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s[1] != '*') {t[s[0] - 96].l = s[1] - 96; t[s[1] - 96].fa = s[0] - 96;}
        if (s[2] != '*') {t[s[0] - 96].r = s[2] - 96; t[s[2] - 96].fa = s[0] - 96;}
    }

    for (int i = 1; i <= 26; i++) {
        if (t[i].fa == 0) {
            root = i;
            break;
        }
    }

    visit(root);
    return 0;
}