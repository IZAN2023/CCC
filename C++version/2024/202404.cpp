#include <bits/stdc++.h>
using namespace std;
// template <typename T>
// void print_vector(vector<T>& vec){
//     for (int i = 0; i < vec.size(); i++) {
//         cout << vec[i];
//         if (i != vec.size() - 1){
//             cout << ",";
//         }
//     }
//     cout << endl;
// }
int main(){
    vector<char> diff_1;
    vector<char> diff_2;
    string str_1;
    string str_2;
    cin >> str_1;
    cin >> str_2;
    char sillykey;
    char wrongkey;
    char quiet_key = '-';
    string new_str;
    for (uint8_t i = 0; i < str_1.size(); i++){
        if (str_2.find(str_1[i]) == string::npos){
            diff_1.push_back(str_1[i]);
        }
    }
    for (char c : str_2){
        if (str_1.find(c) == string::npos){
            diff_2.push_back(c);
        }
    }
    set<char> diff_1_s(diff_1.begin(), diff_1.end());
    // set<char> diff_2_s(diff_2.begin(), diff_2.end()); 
    wrongkey = diff_2[0];
    if (str_1.size() == str_2.size()) {
        sillykey = diff_1[0];
    }
    else{
        auto it = diff_1_s.begin();
        sillykey = *it;
        it++;
        quiet_key = *it;
        // cout << sillykey << quiet_key << endl;
        new_str = "";
        for (char x : str_1){
            if (x == sillykey){
                x = wrongkey;
            }
            else if (x == quiet_key){
                continue;
            }
            new_str += x;
        }

        if (new_str != str_2){
            char temp = sillykey;
            sillykey = quiet_key;
            quiet_key = temp;
        }
    }
    cout << sillykey << " " << wrongkey << endl;
    cout << quiet_key << endl;


    // print_vector(diff_1);
    // print_vector(diff_2);


}