#include <bits/stdc++.h>
using namespace std;
int main(){
    string quote;
    getline(cin, quote);
    int happytime = 0;
    int sadtime = 0;
    size_t pos1 = quote.find(":-)");
    size_t pos2 = quote.find(":-(");
    while (pos1 != string::npos) {
        happytime++;
        pos1 = quote.find(":-)", pos1 + 3);
    }
    while (pos2 != string::npos) {
        sadtime++;
        pos2 = quote.find(":-(", pos2 + 3);
    }
    if (happytime > sadtime){
        cout << "happy" << endl;
    }
    else if (sadtime > happytime){
        cout << "sad" << endl;
    }
    else if (sadtime == 0 && happytime == 0){
        cout << "none" << endl;
    }
    else if (sadtime == happytime){
        cout << "unsure" << endl;
    }
}