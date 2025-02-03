#include <bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin >> num;
    int numagian;
    int total = 0;
    for (int i = 0; i < num/4+1; i++){
        numagian = num - 4 * i;
        if (numagian % 5 == 0){
            total++;
        }
    }
    cout << total;
}