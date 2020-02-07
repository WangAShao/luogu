#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, score1, score2, paper, max = 0, sum = 0, total = 0;
    char leader, west;
    string name, maxn;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        sum = 0;
        cin >> name >> score1 >> score2 >> leader >> west >> paper;
        if (score1 > 80 && paper > 0) {
            sum += 8000;
        } 
        if (score1 > 85 && score2 > 80) {
            sum += 4000;
        }
        if (score1 > 90) {
            sum += 2000;
        }
        if (score1 > 85 && west == 'Y') {
            sum += 1000;
        }
        if (score2 > 80 && leader == 'Y') {
            sum += 850;
        }
        if (sum > max) {
            max = sum;
            maxn = name;
        }
        total += sum;
    }
    cout<<maxn<<endl<<max<<endl<<total;
    return 0;
}