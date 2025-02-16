#include <bits/stdc++.h>
using namespace std;
// template <typename T>
// void print_vec(vector<T> v) {
//     for (const T& elem: v) {
//         cout << elem << " ";
//     }
//     cout << endl;
// }
int main(){
    int r, c;
    cin >> r >> c;
    vector<string> str_list;
    for (int i = 0; i < r; i++){
        string mystr;
        cin >> mystr;
        str_list.push_back(mystr);
    }
    // print_vec(str_list);
    int x, y;
    cin >> x >> y;

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    q.push({x, y});
    visited[x][y] = true;
    vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int total = 0;
    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        char pumpkin = str_list[cx][cy];
        if (pumpkin == 'S') {
            total += 1;
        } else if (pumpkin == 'M') {
            total += 5;
        } else if (pumpkin == 'L') {
            total += 10;
        }

        for (const auto& direction : directions){
            int nx = cx + direction.first;
            int ny = cy + direction.second;
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && str_list[nx][ny] != '*' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

    }
    cout << total << endl;
}