#include <bits/stdc++.h>
using namespace std;
int main(){
    string str1;
    string str2;
    bool yon = false;
    cin >> str1;
    cin >> str2;
    for (int i = 0; i < str2.size(); i++){
        if (str1.find(str2) != string::npos){
            yon = true;
            break;
        }
        char str3 = str2[0];
        str2.erase(0, 1);
        str2.push_back(str3);
    }
    if (yon == true){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}