#include <bits/stdc++.h>

using namespace std;
char table[26];
int s;
bool flag[26];
int main() {
    string passward = "", origin = "", message = "";
    cin >> passward >> origin >> message;

    for (int i = 0; i < passward.length(); i++) {
        if (table[passward[i] - 'A'] == 0) {
            if (!flag[origin[i] - 'A']) {
                table[passward[i] - 'A'] = origin[i];
                ++s;
                flag[origin[i] - 'A'] = true;
            } else {
                printf("Failed\n");
                return 0;
            }
        } else {
            if (table[passward[i] - 'A'] != origin[i]) {
                //出现不匹配
                printf("Failed\n");
                return 0;
            }
        }
    }//end for

    if (s != 26) {
        printf("Failed\n");
        return 0;
    }

    for (int i = 0; i < message.length(); i++) {
        printf("%c", table[message[i] - 'A']);
    }

    return 0; 
}


