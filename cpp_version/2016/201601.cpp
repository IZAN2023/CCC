#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    string together;
    for (int i = 0; i < 6; i++){
        cin >> c;
        together.push_back(c);
    }
    int Wnum = count(together.begin(), together.end(), 'W');
    // cout << Wnum;
    if (Wnum >= 5){
        cout << 1 << endl;
    }
    else if (Wnum ==3 || Wnum ==4){
        cout << 2 << endl;
    }
    else if (Wnum ==1 || Wnum ==2){
        cout << 3 << endl;
    }
    else{
        cout << -1 << endl;
    }


}