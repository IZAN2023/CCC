#include <bits/stdc++.h>
using namespace std;
int main(){
    int S;
    int M;
    int L;
    int total = 0;
    cin >> S;
    cin >> M;
    cin >> L;
    total = 1*S + 2*M + 3*L;
    if (total >= 10){
        cout << "happy" << endl;
    }
    else{
        cout << "sad" << endl;
    }
}