//https://dmoj.ca/problem/ccc17j3
//CCC '17 J3 - Exactly Electrical


#include <bits/stdc++.h>
using namespace std;
int main(){
    int x1, y1;
    int x2, y2;
    int T;
    int n;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> T;
    n = abs(x2-x1) + abs(y2-y1);
    if (T >=n && (T - n) % 2 == 0){
        cout << "Y" << endl;
    }
    else{
        cout << "N" << endl;
    }
}