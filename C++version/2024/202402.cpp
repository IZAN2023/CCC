#include <iostream>
using namespace std;
int main(){
    int D;
    int U;
    cin >> D;
    while (true){
        cin >> U;
        if (D <= U){
            cout << D << endl;
            break;
        }
        D += U;
    }



    return 0;
}