#include <bits/stdc++.h>
using namespace std;
int main(){
    int mins;
    cin >> mins;
    int mins_a;
    int hour2 = 2;
    int hour1 = 1;
    int min1 = 0;
    int min2 = 0;
    int total = 0;
    if (mins > 720){
        total += mins/720 *31;
        mins_a = mins%720;
    }
    else{
        mins_a = mins;
    }
    
    for (int i = 0; i < mins_a; i++){
        if (min2 == 9){
            min2 = 0;
            if (min1 == 5){
                min1 = 0;
                if (hour2 == 2 && hour1 == 1){
                    hour1 = 0;
                    hour2 = 1;
                }
                else if (hour2 == 9){
                    hour1++;
                }
                else{
                    hour2++;
                }
            }
            else{
                min1++;
            }
        }
        else{
            min2++;
        }
        // cout << hour1 << hour2 << ":" << min1 << min2 << endl;
        if ((hour1 == 0 &&(min1 - min2 == hour2 - min1)) || ((hour1 - hour2 == hour2 - min1) && (hour2 - min1 == min1 - min2))){

            total++;
        }

    }
    cout << total << endl;

}