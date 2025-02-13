#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    int b;
    int c;
    int d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    if ((a == 9 || a == 8) && b == c && (d == 9 || d == 8)){
        cout << "ignore" << endl;
    }
    else{
        cout << "answer" << endl;
    }
}