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
    size_t pos; 
    vector<string> ansvector;
    // cout << "test" << endl;
    cin >> n;
    cin.get();


    for (int i = 0; i < n; i++){
        getline(cin, myinput);
        pos = myinput.find(' ');
        string beforespace = myinput.substr(0, pos);
        char afterspace = myinput[pos + 1];
        string ans(stoi(beforespace), afterspace);
        ansvector.push_back(ans);
    }
    print_vector(ansvector);

    
    return 0;
}