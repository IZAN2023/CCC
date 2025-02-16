//https://dmoj.ca/problem/ccc16j2
//CCC '16 J2 - Magic Squares

#include <bits/stdc++.h>
using namespace std;
int main(){
    // int n11, n12, n13, n14;
    // int n21, n22, n23, n24;
    // int n31, n32, n33, n34;
    // int n41, n42, n43, n44;
    // cin >> n11 >> n12 >> n13 >> n14;
    // cin >> n21 >> n22 >> n23 >> n24;
    // cin >> n31 >> n32 >> n33 >> n34;
    // cin >> n41 >> n42 >> n43 >> n44;

    // int a1 = n11 + n12 + n13 + n14;
    // int a2 = n21 + n22 + n23 + n24;
    // int a3 = n31 + n32 + n33 + n34;
    // int a4 = n41 + n42 + n43 + n44;
    // int b1 = n11 + n21 + n31 + n41;
    // int b2 = n12 + n22 + n32 + n42;
    // int b3 = n13 + n23 + n33 + n43;
    // int b4 = n14 + n24 + n34 + n44;

    // // cout << a1 << a2 << a3 << a4 << b1 << b2 << b3 << b4 << endl;
    // if (a1 == a2 && a2 == a3 && a3 == a4 && a4 == b1 && b1 == b2 && b2 == b3 && b3== b4){
    //     cout << "magic" << endl;
    // }
    // else{
    //     cout << "not magic" << endl;
    // }

    vector<vector<int>> vec(4, vector<int>(4, 0));
    int sum = 0;
    int rowSum = 0;
    int colSum = 0;
    bool result = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        sum += vec[0][i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            rowSum += vec[i][j];
            colSum += vec[j][i];
        }
        if ((rowSum != sum) || (colSum != sum)) {
            result = false;
            break;
        }
        rowSum = 0;
        colSum = 0;
    }

    if (result) {
        cout << "magic" << endl;
    } else {
        cout << "not magic" << endl;
    }

}