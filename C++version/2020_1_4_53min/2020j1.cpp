#include <bits/stdc++.h>
using namespace std;
int main(){
    int S;
    cin >> S;
    int M;
    cin >> M;
    int L;
    cin >> L;
    int total;
    total = 1*S + 2*M + 3*L;
    if (total >= 10){
        cout << "happy" << endl;
    }
    else{
        cout << "sad" << endl;
    }
}