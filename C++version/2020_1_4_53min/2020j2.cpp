#include <bits/stdc++.h>
using namespace std;
int main (){
    int target;
    int n1;
    int n2;
    cin >> target;
    cin >> n1;
    cin >> n2;
    int times = 0;
    int total = 0;
    int i = 1;
    total += n1;
    while (true){
        if (total > target){
            break;
        }
        total += pow(n2, i)*n1;

        i++;
        // cout << i << endl;
        times++;
    }
    cout << times;

}