#include <bits/stdc++.h>
using namespace std;

// template <typename T>
// void print_2d_vec(const vector<vector<T>>& v){
//     for(const vector<T>& row : v) {
//         for(const T& elem : row) {
//             cout << elem << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }


int dfs(const vector<vector<char>>& grid, const string& target, int x, int y){
    int count = 0;
    vector<vector<int>> directions = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    for (auto& direction : directions){
        stack<tuple<int, int, int, bool, vector<int>>> s;
        s.push({x, y, 0, false, direction});
        while(!s.empty()){
            auto [cx, cy, index, turned, main_dir] = s.top();
            s.pop();
            if (index == target.size()-1){
                // cout <<"找到了" << cx << " "<< cy << " " << index << endl;
                count++;
                continue;
            }
            vector<int> turn90 = {main_dir[1], -main_dir[0]};
            vector<int> turn270 = {-main_dir[1], main_dir[0]};
            vector<pair<vector<int>, bool>> newdics_with_turned = {{main_dir, turned}};
            if (!turned && index > 0) { // index是个坑，第二个字符才能转弯，否则会有重复
                newdics_with_turned.push_back({turn90, true});
                newdics_with_turned.push_back({turn270, true});
            }
            for (const auto& dir_with_turned : newdics_with_turned){
                int nx = cx + dir_with_turned.first[0];
                int ny = cy + dir_with_turned.first[1];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == target[index+1]){
                    // cout << "push: " << nx << " " << ny  <<" turned: "<<  dir_with_turned.second << endl;
                    s.push({nx, ny, index+1,  dir_with_turned.second, dir_with_turned.first});
                }
            }

        }
    }
    return count;
}


int main(){

    string target;
    int r, c;
    cin >> target >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }

    // print_2d_vec(letterlist);
    int count = 0;

    for(int i = 0; i < r; i++){
        for(int j = 0; j<c; j++){
            if (grid[i][j] == target[0]) {
                // cout << i << " " << j << endl;
                count += dfs(grid, target, i, j);
            }
        }
    }
    cout << count;

}