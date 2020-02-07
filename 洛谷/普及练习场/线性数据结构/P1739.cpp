#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    cin >> c;
    int ans = 0;
    while (c != '@') {
        if (c == '(') ans++;
        else if (c == ')') ans--;
        if (ans < 0) {
            cout << "NO";
            return 0;
        }
        cin >> c;
    }

    if (ans == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}