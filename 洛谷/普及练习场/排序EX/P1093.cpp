#include <bits/stdc++.h>

using namespace std;

struct student {
    int math;
    int chinese;
    int english;
    int id;
    int total;
} p[301];

bool cmp (const student& a, const student& b) {
    if (a.total != b.total) {
        return a.total > b.total;
    } else {
        if (a.chinese != b.chinese) {
            return a.chinese > b.chinese;
        } else {
            return a.id < b.id;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].chinese >> p[i].math >> p[i].english;
        p[i].id = i;
        p[i].total = p[i].chinese + p[i].math + p[i].english; 
    }

    sort(p + 1, p + n + 1, cmp);

    for (int i = 1; i <= 5; i++) {
        cout << p[i].id << " " << p[i].total << endl;
    }
    return 0;
}
