#include <bits/stdc++.h>
using namespace std;
int main() {
    string myinput;
    cin >> myinput;
    int mylength = myinput.size();
    for (int i = 0; i < mylength; i++){
        if (myinput[i] == '+'){
            cout << " tighten ";
        } 
        else if (myinput[i] == '-'){
            cout << " loosen ";
        }
        else if (isdigit(myinput[i]) && isalpha(myinput[i+1])){
            cout << myinput[i] << endl;
        }
        else{
            cout << myinput[i];
        }
    }
}