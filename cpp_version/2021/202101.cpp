//https://dmoj.ca/problem/ccc21j1
//CCC '21 J1 - Boiling Water

#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int P;
    cin >> N;
    P = 5 * N -400;
    cout << P << endl;
    if (P > 100){
        cout << "-1";
    }
    else if (P < 100){
        cout << "1";
    }
    else if (P == 100){
        cout << "0";
    }
}