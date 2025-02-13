#include <bits/stdc++.h>
using namespace std;
int main(){
    int n1;
    int n2;
    int ans=0;
    int square;
    cin >> n1;
    cin >> n2;
    ans+=n1;
    // cout << ans << endl;
    for (int i = 0; i < n2; i++){
        // cout << ans << endl;
        square = pow(10, i+1);
        ans += n1 * square;
    }
    cout << ans << endl;
}