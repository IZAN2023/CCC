#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string dayone;
    string daytwo;
    int total = 0;
    cin >> dayone;
    cin >> daytwo;
    for (int i = 0; i < n; i++){
        // cout << "yes!" << ' ' << dayone[i] << ' ' << daytwo[i] << endl;
        if ((dayone[i] == 'C') && (daytwo[i] == 'C')){
            // cout << "yessir!" << endl;
            total++;
        }
    }
    cout << total << endl;
}