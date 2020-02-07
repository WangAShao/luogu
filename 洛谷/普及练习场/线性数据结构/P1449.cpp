#include <bits/stdc++.h>

using namespace std;

long long s[1010];
int top, num;

int main() {
    char c;
    cin >> c;
    while (c != '@') {
        if (c >= '0' && c <= '9') {
            num = c - '0';
            while((c = getchar()) != '.') {
                num = num * 10 + c - '0';
            }
            s[top++] = num;
        }

        else {
            int a = s[--top];
            int b = s[--top];
            switch (c)
            {
            case '+':
                num = a + b;
                break;
            
            case '-':
                num = b - a;
                break;

            case '*':
                num = a * b;
                break;
            
            case '/':
                num = b / a;
                break;
            default:
                break;
            }
            s[top++] = num;
        }
        cin >> c;
    }
    cout << s[0];
    return 0;
}