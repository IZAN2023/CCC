#include <bits/stdc++.h>
using namespace std;
int main(){
    string my_input;
    cin >> my_input;
    for (int i =0; i<my_input.size(); i++){
        if (my_input[i] == '+'){
            cout << " tighten ";
        }
        else if (my_input[i] == '-'){
            cout << " loosen ";
        }
        else if (isdigit(my_input[i]) && isalpha(my_input[i+1])){
            cout << my_input[i] << endl;
        }
        else{
            cout << my_input[i];
        }
    }
}