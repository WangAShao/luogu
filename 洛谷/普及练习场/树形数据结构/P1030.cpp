#include <bits/stdc++.h>

using namespace std;

void solve (string mid, string after) {
    
    if (after.size() > 0) {
        char ch;
        ch = after[after.size() - 1];
        cout << ch;
        int k = mid.find(ch);

        //这里特别注意一下: after.substr(k,in.size()-k-1))是因为substr(下标,你想取的长度)，比如string a = "1234567",a.substr(2,3)="345"
        solve(mid.substr(0, k), after.substr(0, k));
        solve(mid.substr(k + 1), after.substr(k, mid.size() - k - 1));
    }
}

int main() {
    string midStr, afterStr;
    cin >> midStr >> afterStr;
    solve(midStr, afterStr);
    return 0;
}