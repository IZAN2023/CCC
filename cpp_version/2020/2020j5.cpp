#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> cal_factor(int number, int row, int col){
    vector<pair<int, int>> result;
    for (int i =1; i*i <= number; i++){
        if (number % i == 0){
            int nx = i -1, ny = (number/i) - 1;
            if (nx < row && ny < col){
                result.push_back({nx, ny});
            }
            if (ny < row && nx < col && nx != ny){
                result.push_back({ny, nx});
            }
        }
    }
    return result;
}
int main(){
    int R,C;
    cin >> R >> C;
    vector<vector<int>> grid (R, vector<int>(C, 0));
    for(int i = 0; i <=R-1; i++){
        for(int j = 0; j <= C-1; j++){
            cin >> grid[i][j];
        }
    }
    set<int> memo;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();
        if (cx == R-1 && cy == C-1){
            cout << "yes" << endl;
            return 0;
        }
        if (memo.find(grid[cx][cy]) != memo.end()){
            continue;
        }
        vector<pair<int, int>> next_plan = cal_factor(grid[cx][cy], R, C);
        for (const auto& elem : next_plan){
            auto [nx, ny] = elem;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
        memo.insert(grid[cx][cy]);
    }
    cout << "no" << endl;
    return 0;
}