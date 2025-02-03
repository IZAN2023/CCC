#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.get();
    string line1;
    string line2;
    int total = 0;
    getline(cin, line1);
    getline(cin, line2);
    line1.erase(remove(line1.begin(), line1.end(), ' '), line1.end());
    line2.erase(remove(line2.begin(), line2.end(), ' '), line2.end());
    // cout << line1 << endl;
    // cout << line2 << endl;
    for (int i =0; i<n; i++){
        if (line1[i] == '1'){
            // cout << 1 << endl;
            total+=3;
        }
        if (line2[i] == '1'){
            // cout << 1 << endl;
            total+=3;
        }
        if ((line1[i] == '1') && (line1[i+1] == '1')){
            // cout << 2 << endl;
            total-=2;
        }
        if ((i%2==0) && (line1[i] == '1') && (line2[i] == '1')){
            // cout << 3 << endl;
            total-=2;
        }
        else if ((i%2==0) && (line2[i] == '1') && (line1[i] == '1')){
            // cout << i;
            // cout << 5 << endl;
            total-=2;
        }
        if ((line2[i] == '1') && (line2[i+1] == '1')){
            // cout << 4 << endl;
            total-=2;
        }

    }
    cout << total << endl;
}

