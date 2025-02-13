// CCC '22 J5 - Square Pool
// Canadian Computing Competition: 2022 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc22j5

// 此解法能拿到 8 分
#include <bits/stdc++.h>
using namespace std;

// 调试过程中打印二维数组的函数
template <typename T>
void print_2d_vec(const vector<vector<T>>& v){
    for(const vector<T>& row : v) {
        for(const T& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    // dp表，记录以dp[i][j]为右下角的正方形最大边长
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        grid[x - 1][y - 1] = 1;
    }

    // print_2d_vec(grid);

    int max_side = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                //有树的地方，最长度为0
                dp[i][j] = 0;
            } else if(i == 0 || j == 0) {
                // row 0 和 col 0 最大长度为1
                dp[i][j] = 1;
            } else {
                // 状态转移，斜上方、上方、左侧格子的最小dp边长 + 1，即本格子的dp边长
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            max_side = max(max_side, dp[i][j]);
            // print_2d_vec(dp);
        }
    }

    cout << max_side << endl;
}