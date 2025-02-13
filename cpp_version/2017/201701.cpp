#include <bits/stdc++.h>
using namespace std;
int main(){
    int n1;
    int n2;
    cin >> n1;
    cin >> n2;
    if (n1 <0 && n2 >0){
        cout << 2 << endl;
    }
    else if (n1 >0 && n2 >0){
        cout << 1 << endl;
    }
    else if (n1 <0 && n2 <0){
        cout << 3 << endl;
    }
    else if (n1 >0 && n2 <0){
        cout << 4 << endl;
    }
}