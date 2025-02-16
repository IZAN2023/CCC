//https://dmoj.ca/problem/ccc19j1
//CCC '19 J1 - Winning Score

#include <bits/stdc++.h>
using namespace std;
int main(){
    int appletotal = 0;
    int bananatotal = 0;
    for(int i = 3; i >= 1; i--){
        int n;
        cin >> n;
        appletotal += n * i;
    }
    for(int i =3; i >= 1; i--){
        int n1;
        cin >> n1;
        bananatotal += n1 * i;
    }
    if (appletotal > bananatotal){
        cout << "A" << endl;
    }
    else if (bananatotal > appletotal){
        cout << "B" << endl;
    }
    else{
        cout << "T" << endl;
    }
    return 0;
}

