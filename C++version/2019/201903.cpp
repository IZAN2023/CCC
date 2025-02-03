#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<string>& vec){
    for (string& elem : vec){
        cout << elem << endl;
    }
}
int main(){
    int n;
    string myinput;
    int total = 1;
    string mypushback;
    vector<string> ansvector; 
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> myinput;
        for (int k = 0; k < myinput.size(); k++){
            if (myinput[k] == myinput[k+1]){
                total++;
            }
            else{
                mypushback += to_string(total) + ' ' + myinput[k] + ' ';
                // cout << total << endl;
                // cout << myinput[k] << endl;
                total = 1;
            }
        }
        // cout << mypushback;
        ansvector.push_back(mypushback);
        mypushback.clear();
    }
    print_vector(ansvector);
}