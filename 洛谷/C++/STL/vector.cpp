#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> v0;

    v0.reserve(3);

    vector <int> v1(3);
    vector <int> v2(3, 2);
    vector <int> v3(3, 1, v2.get_allocator());
    vector <int> v4(v2);
    vector <int> v5(v2.begin() + 1, v2.begin() + 3);
    vector <int> v6(move(v2));

    // 以下是测试代码，有兴趣的同学可以自己编译运行一下本代码。
cout << "v1 = ";
copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v2 = ";
copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v3 = ";
copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v4 = ";
copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v5 = ";
copy(v5.begin(), v5.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v6 = ";
copy(v6.begin(), v6.end(), ostream_iterator<int>(cout, " "));
cout << endl;
}