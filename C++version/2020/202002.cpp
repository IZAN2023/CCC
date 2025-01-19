#include <bits/stdc++.h>
using namespace std;

int main(){
    int P;
    int N;
    int R;
    int total = 0;
    int day = 1;
    cin >> P;
    cin >> N;
    cin >> R;
    total = N;
    while (total <= P){
        total += pow(R, day)*N;
        day++;
    }
    cout << day-1 << endl;
    return 0;
}