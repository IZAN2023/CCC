//https://dmoj.ca/problem/ccc21j4
//CCC '21 J4 - Arranging Books

#include <bits/stdc++.h>
using namespace std;

int main(){
    int num_l = 0;
    int num_m = 0;
    int misplaced_l = 0;
    int misplaced_m = 0;
    string shelf;
    cin >> shelf;
    int m_in_l = 0;
    int l_in_m = 0;
    //得知出现了多少个L和M
    for (char c : shelf){
        if (c == 'L'){
            num_l++;
        }
        else if (c == 'M'){
            num_m++;
        }
    }
    //如果第i个是非L就加次数
    for (int i = 0; i < num_l; i++){
        if (shelf[i] == 'M'){
            m_in_l++;
            misplaced_l++;
        }
        else if (shelf[i] == 'S'){
            misplaced_l++;
        }
    }
    //如果第j个不是非L就加次数
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
