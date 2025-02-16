//https://dmoj.ca/problem/ccc19s1
//CCC '19 S1 - Flipper

#include <bits/stdc++.h>
using namespace std;
int main(){
    string change;
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    cin >> change;
    for (size_t i = 0; i < change.size(); i++){
        if (change[i] == 'V'){
            swap(n1,n2);
            swap(n3,n4);
        }
        else if (change[i] == 'H'){
            swap(n1,n3);
            swap(n2,n4);
        }
    }
    cout << n1 << ' ' << n2 << endl;
    cout << n3 << ' ' << n4 << endl;
}