//https://dmoj.ca/problem/ccc22s2
//CCC '22 J4 - Arranging Books

#include <bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin >> num;
    int remainning;
    int total = 0;
    for (int i = 0; i < num/4+1; i++){
        remainning = num - 4 * i;
        if (remainning % 5 == 0){
            total++;
        }
    }
    cout << total << endl;
}