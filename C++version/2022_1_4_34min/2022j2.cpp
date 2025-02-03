#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i< n; i++){
        int points;
        cin >> points;
        int fouls;
        cin >> fouls;
        int star;
        star = points*5-fouls*3;
        if (star > 40){
            total++;
        }
    }
    if (total == n){
        cout << total << '+';
    }
    else{
        cout << total;
    }
}