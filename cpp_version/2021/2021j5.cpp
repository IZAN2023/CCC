#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<int> row_flips(a, 0); // 记录每行的翻转次数
    vector<int> col_flips(b, 0); // 记录每列的翻转次数

    for (int i = 0; i < n; i++) {
        char rorc;
        int num;
        cin >> rorc >> num;
        if (rorc == 'R') {
            row_flips[num - 1]++;
        } else {
            col_flips[num - 1]++;
        }
    }

    int count = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            // 如果行翻转次数 + 列翻转次数是奇数，则值为 1
            if ((row_flips[i] + col_flips[j]) % 2 == 1) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}