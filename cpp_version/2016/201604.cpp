//https://dmoj.ca/problem/ccc16j4
//CCC '16 J4 - Arrival Time

#include <bits/stdc++.h>
using namespace std;
int main(){
    string time;
    double pass = 120.0;
    cin >> time;
    int pos = time.find(':');
    string hours = time.substr(0,pos);
    string mins = time.substr(pos+1);
    string out1;
    string out2;
    int hour = stoi(hours);
    int min = stoi(mins);
    // cout << hour << min;
    while (pass > 0){
        if ((7 <= hour && hour < 10) || (15 <= hour && hour < 19)){
            pass -= 0.5;
        }
        else {
            pass -= 1;
        }
        min += 1;
        if (min == 60){
            hour += 1;
            min = 0;
            if (hour == 24){
                hour = 0;
            }
        }
    }
    if (hour < 10) {
        out1 = "0" + to_string(hour);
    } else {
        out1 = to_string(hour);
    }

    if (min < 10) {
        out2 = "0" + to_string(min);
    } else {
        out2 = to_string(min);
    }
    cout << out1 << ':' << out2 << endl;
}