#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> grid;
vector<vector<bool>> dp;

void solve() {
    cin >> R >> C;
    grid.assign(R + 1, vector<int>(C + 1, 0));
    dp.assign(R + 1, vector<bool>(C + 1, false));

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> grid[i][j];
        }
    }

    dp[1][1] = true;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            if (dp[r][c]) { 
                int value = grid[r][c];
                for (int i = 1; i * i <= value; ++i) {
                    if (value % i == 0) {
                        int j = value / i;
                        if (i <= R && j <= C){
                            dp[i][j] = true;
                        }
                        if (j <= R && i <= C){
                            dp[j][i] = true;
                        } 
                    }
                }
            }
        }
    }

    cout << (dp[R][C] ? "yes" : "no");
}

int main() {
    solve();
    return 0;
}
