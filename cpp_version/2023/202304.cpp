//https://dmoj.ca/problem/ccc23s1
//CCC '23 S1 - Trianglane

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int result = 0;

    vector<vector<int>> grid(2, vector<int>(n));

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        if(grid[0][i] == 1) {
            result += 3;
        }
        if(grid[1][i] == 1) {
            result += 3;
        }

        // 偶数列上下都有，要减2
        if ((i % 2 == 0) && (grid[0][i] == 1) && (grid[1][i] == 1)){
            result -= 2;
        }

        // 每一行，相邻的两个，要减2
        if((i != n - 1) && grid[0][i] == 1 && grid[0][i + 1] == 1) {
            result -= 2;
        }
        if((i != n - 1) && grid[1][i] == 1 && grid[1][i + 1] == 1){
            result -= 2;
        }
    }
    cout << result << endl;
}

