#include <iostream>
#include <string>

using namespace std;

class bigint {
    private: 
        int value[10005];
        short len;
    public:
        bigint(int n);
        bigint();
        friend ostream& operator<< (std::ostream& output, bigint c);
        friend istream& operator>> (std::istream& input, bigint& c);
        friend bigint operator+ (bigint a, bigint b);
};

int main() {
    bigint a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}

bigint::bigint(int n) {
    for (int i = 0; i < 10005; i++) {
        value[i] = 0;
    } 

    n = n >= 0 ? n : -n;
    for (len = 1; n; len++, n /= 10) {
        value[len] = n % 10;
    }
    len--;
}

bigint::bigint() {
    for (int i = 0; i < 10005; i++) {
        value[i] = 0;
    }

    len = 0;
}

ostream& operator<< (ostream& output, bigint c) {
    if (c.len == 0) {
        cout << 0;
        return output;
    }

    for (int i = c.len; i > 0; i--) {
        output << c.value[i];
    }

    return output;
}

istream& operator>> (istream& input, bigint& c) {
    std::string s;
    input >> s;
    int i = s.length();
    int j = 0;
    c.len = s.length();

    for (; i > 0; i--, j++) {
        c.value[i] = s[j] - '0';
    }

    return input;
}

bigint operator+ (bigint a, bigint b) {
    bigint c;
    int max;
    if (a.len >= b.len) {
        max = a.len;
    } else {
        max = b.len;
    }

    for (int i = 1; i <= max; i++) {
        c.value[i] += a.value[i] + b.value[i];
        c.value[i + 1] = c.value[i] / 10;
        c.value[i] %= 10;
    }

    if (c.value[max + 1] == 0) {
        c.len = max;
    } else {
        c.len = max + 1;
    }

    return c;
}