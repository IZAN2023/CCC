//https://dmoj.ca/problem/ccc15j1
//CCC '15 J1 - Special Day

#include <bits/stdc++.h>
using namespace std;
int main(){
    int month;
    int day;
    cin >> month;
    cin >> day;
    if (month > 2){
        cout << "After" << endl;
    }
    else if (month < 2){
        cout << "Before" << endl;
    }
    else if (month == 2){
        if (day < 18){
            cout << "Before" << endl;
        }
        else if (day > 18){
            cout << "After" << endl;
        }
        else if (day == 18){
            cout << "Special" << endl;
        }
    }
}