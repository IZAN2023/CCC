//https://dmoj.ca/problem/ccc22j2
//CCC '22 J2 - Fergusonball Ratings


#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int point;
    int fouls;
    int num;
    int total = 0;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> point;
        cin >> fouls;
        num = point *5 - fouls *3;
        if (num >= 40){
            total++;
        }
    }
    if (total == N){
        cout << total << "+" << endl;
    }
    else {
        cout << total << endl;
    }
}