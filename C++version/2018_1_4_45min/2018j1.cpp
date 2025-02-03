#include <bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2,n3,n4;
    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    if ((n1 == 8 || n1 == 9) && n2==n3 && (n4 == 8 || n4 == 9)){
        cout << "ignore";
    }
    else{
        cout << "answer";
    }
}