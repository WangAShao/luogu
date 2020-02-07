#include <bits/stdc++.h>

using namespace std;
int a[10100], b[10100], res[10100], maxl;
bool flag = false;

int cmp (string str1, string str2) {
    if (str1.length() > str2.length()) {
        return 1;
    } else if (str1.length() < str2.length()) {
        return -1;
    } else {
        return str1.compare(str2);
    }
}

string sub(string str1, string str2) {
    string str;
    int cf = 0; //用来标记是否借位
    int tmp = str1.length() - str2.length();

    for (int i = str2.length() - 1; i >= 0; i--) {
        if (str1[tmp + i] < str2[i] + cf) {
            str = char(str1[tmp + i] - str2[i] - cf + '0' + 10) + str;
            cf = 1;
        } else {
            str = char(str1[tmp + i] - str2[i] - cf + '0') + str;
            cf = 0;
        }
    }

    for (int i = tmp - 1; i >= 0; i--) {
        if (str1[i] - cf >= '0') {
            str = char(str1[i] - cf) + str;
            cf = 0;
        } else {
            str = char(str1[i] - cf + 10) + str;
            cf = 1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));//去除结果中多余的前导0
    return str;
}

int main() {
    string a;
    string b;
    cin >> a >> b;

    if (cmp(a, b) == 0) {
        cout << 0 << endl;
    } else if (cmp(a, b) < 0) {
        swap(a, b);
        cout << '-' << sub(a, b) << endl;
    } else {
        cout << sub(a, b) << endl;
    }

    return 0;
}