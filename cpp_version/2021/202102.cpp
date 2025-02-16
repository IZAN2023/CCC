//https://dmoj.ca/problem/ccc21j2
//CCC '21 J2 - Silent Auction

#include <bits/stdc++.h>
using namespace std;

int main() {
    string highest_name;
    string now_name;
    int highest_num = -1;
    int now_num;
    int times;
    cin >> times;

    for (int i = 0; i < times; i++) {
        cin >> now_name;
        cin >> now_num;
        
        if (now_num > highest_num) {
            highest_num = now_num;
            highest_name = now_name;
        }
    }

    cout << highest_name;
}
