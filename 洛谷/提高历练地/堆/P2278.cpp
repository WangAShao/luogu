#include <bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int arrival;
    int tim;
    int pri;
    bool operator < (const Process& a) const {
        if (pri == a.pri) {
            return arrival > a.arrival;
        } else {
            return pri < a.pri;
        }
    }
} c;

long long ti;
priority_queue <Process> q;

int main() {
    while (cin >> c.id >> c.arrival >> c.tim >> c.pri) {
        while (!q.empty() && ti + q.top().tim <= c.arrival) {
            Process b = q.top();
            q.pop();
            printf("%d %lld\n", b.id, b.tim + ti);
            ti += b.tim;
        }

        if (!q.empty()) {
            Process d = q.top();
            q.pop();
            d.tim = d.tim - c.arrival + ti;
            q.push(d);
        }

        q.push(c);
        ti = c.arrival;
    }

    while (!q.empty()) {
        Process f = q.top();
        q.pop();
        ti += f.tim;
        printf("%d %lld\n", f.id, ti);
    }
    return 0;
}