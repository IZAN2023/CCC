// CCC '22 J5 - Square Pool
// Canadian Computing Competition: 2022 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc22j5

// 此解法能拿到 8 分，实现方式为v1基础上的grid和dp空间压缩
// 为什么要进行压缩？因为题目明确说了，要拿到额外的7分，n ≤ 500000，t ≤ 100，因此考虑通过将二维数组降为一维数组进行空间压缩
// 但压缩后，为何依旧不得分？因为n实在太大了，看来要想其他办法才行
// 虽然没有成功，但是这里在v1基础上的空间压缩技巧依旧是值得借鉴的，因此保留此版本解法

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    // 不用grid记录yard了，干脆直接记数的坐标
    set<pair<int, int>> trees;

    // 由于 dp[i][j] 只依赖于 当前行的左侧 (dp[i][j-1]) 和 上一行的相邻位置 (dp[i-1][j-1] 和 dp[i-1][j])，
    // 我们可以用 一维数组 dp 来存储当前行，并用一个变量 prev 来保存 dp[i-1][j-1] 的值。
    vector<int> dp(n, 0);

    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        trees.insert({x - 1, y - 1});
    }

    // print_2d_vec(grid);

    int max_side = 0;

    for(int i = 0; i < n; i++){
        // 用prev记录dp[i - 1][j - 1]，即斜上角的值, 每行开始的时候，prev初始化为0，因为第一列的斜上角是没有数值的
        int prev = 0;
        for(int j = 0; j < n; j++) {
            // 临时记录下dp[j]此刻的值，这是上一行记录下的这个点的值，本轮for即将对他进行更新，但这个值对下一个dp[j]来说就是斜上角的值
            // 所以要把这个值带到j的下一轮循环里去
            int temp = dp[j];
            // 改成查set，如果查到的结果为trees.end()，说明set中无记录
            if(trees.find({i, j}) != trees.end()) {
                //有树的地方，最长度为0
                dp[j] = 0;
            } else if(i == 0 || j == 0) {
                // row 0 和 col 0 最大长度为1
                dp[j] = 1;
            } else {
                // 状态转移，斜上方、上方、左侧格子的最小dp边长 + 1，即本格子的dp边长
                dp[j] = min(prev, min(dp[j], dp[j - 1])) + 1;
            }
            max_side = max(max_side, dp[j]);
            // prev是在外面一层for中声明的，把temp给它，它可以带到j的下一轮
            prev = temp;
        }
    }

    cout << max_side << endl;
}