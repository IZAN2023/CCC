#include <bits/stdc++.h>
using namespace std;

// template <typename T>
// void print_vector(vector<T>& vec){
//     for (T& elem : vec) {
//         cout << elem << " ";
//     }
//     cout << endl;
// }
// void print_set(const set<int>& s){
//     for(const int& elem : s){
//         cout << elem << " ";
//     }
//     cout << endl;
// }

int main(){

    vector<int> my_list;
    int n;
    int v;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> v;
        my_list.push_back(v);
    } 
    sort(my_list.begin(), my_list.end());

    // print_vector(my_list);
    set<int> myset(my_list.begin(), my_list.end());

    auto it = myset.rbegin(); //反向迭代器，因为出来的大的在后，小的在前。

    advance(it, 2); //给it移动2步到倒数第三个。
    int thirdnum = *it;
    int cnt = std::count(my_list.begin(), my_list.end(), thirdnum);
    cout << thirdnum << " " << cnt << endl;

}