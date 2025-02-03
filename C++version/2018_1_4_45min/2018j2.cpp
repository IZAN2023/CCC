#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string l1;
    string l2;
    cin >> l1;
    cin >> l2;
    int total = 0;
    for (int i = 0; i < n; i++){
        if (l1[i] == 'C' && l2[i] == 'C'){
            total++;
        }
    }
    cout << total;
}