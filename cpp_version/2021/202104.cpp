#include <bits/stdc++.h>
using namespace std;
// int main(){
//     string str_1;
//     string str_2;
//     int total = 0;
//     cin >> str_1;
//     str_2 = str_1;
//     sort(str_1.begin(), str_1.end());
//     // cout << str_1;
//     for (size_t i = 0; i < str_2.size(); i++){
//         if (str_1[i] != str_2[i]){
//             total++;
//         }
//     }
//     if (total % 2 != 0){
//         cout << total /2 +1 << endl;
//     }
//     else if (total %2 == 0){
//         cout << total/2 << endl;
//     }

// }
int main(){
    int num_l = 0;
    int num_m = 0;
    int misplaced_l = 0;
    int misplaced_m = 0;
    string shelf;
    cin >> shelf;
    int m_in_l = 0;
    int l_in_m = 0;
    for (char c : shelf){
        if (c == 'L'){
            num_l++;
        }
        else if (c == 'M'){
            num_m++;
        }
    }
    for (int i = 0; i < num_l; i++){
        if (shelf[i] == 'M'){
            m_in_l++;
            misplaced_l++;
        }
        else if (shelf[i] == 'S'){
            misplaced_l++;
        }
    }
    for (int j = num_l; j < num_l+num_m; j++){
        if (shelf[j] == 'L'){
            l_in_m++;
            misplaced_m++;
        }
        else if (shelf[j] == 'S'){
            misplaced_m++;
        }
    }
    cout << misplaced_l + misplaced_m - min(m_in_l, l_in_m) << endl;
}
