#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_2d_vec(const vector<vector<T>>& v){
    for (const vector<T>& row : v){
        for (const T& elem : row){
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<vector<int>> grid(n, vector<int>(n, 0));
    // print_2d_vec(grid);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int num;
    cin >> num;
    int maxv = 0;
    for (int i = 0; i < num; i++){
        int a, b;
        cin >> a >> b;
        grid[a-1][b-1] = 1;
    }
    // print_2d_vec((grid));
    for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
            if ((j == 0 || k == 0) && grid[j][k] != 1){
                dp[j][k] = 1;
            }
            else if (grid[j][k] == 1){
                dp[j][k] = 0;
            }
            else if (grid[j-1][k] != 1 && grid[j][k-1] != 1 && grid[j-1][k-1] != 1){
                dp[j][k] = min(dp[j-1][k], min(dp[j][k-1], dp[j-1][k-1])) + 1;
            }
            else{
                dp[j][k] = 1;
            }
            maxv = max(maxv, dp[j][k]);
        }
    }
    // print_2d_vec(dp);
    cout << maxv << endl;
}