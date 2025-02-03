#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> vec(4, vector<int>(4, 0));
    int sum = 0;
    int rowsum = 0;
    int colsum = 0;
    bool result = true;
    for (int i = 0; i <4; i++){
        for (int j = 0; j <4; j++){
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i <4; i++){
        sum += vec[0][i];
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            rowsum += vec[i][j];
            colsum += vec[j][i];
        }
        if (rowsum != sum || colsum != sum){
            result = false;
            break;
        }
        rowsum = 0;
        colsum = 0;
    }

    if (result) {
        cout << "magic" << endl;
    }
    else {
        cout << "not magic" << endl;
    }
}