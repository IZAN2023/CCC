#include <bits/stdc++.h>
using namespace std;
int main(){
    int num_1_apple;
    int num_2_apple;
    int num_3_apple;
    int num_1_banana;
    int num_2_banana;
    int num_3_banana;
    int appletotal;
    int bananatotal;
    cin >> num_1_apple;
    cin >> num_2_apple;
    cin >> num_3_apple;
    cin >> num_1_banana;
    cin >> num_2_banana;
    cin >> num_3_banana;
    appletotal = num_1_apple*3 +num_2_apple*2 +num_3_apple*1;
    bananatotal = num_1_banana*3 +num_2_banana*2 +num_3_banana*1;
    if (appletotal > bananatotal){
        cout << "A" << endl;
    }
    else if (bananatotal > appletotal){
        cout << "B" << endl;
    }
    else{
        cout << "T" << endl;
    }
    return 0;
}

