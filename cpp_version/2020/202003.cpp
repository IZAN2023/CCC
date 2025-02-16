//https://dmoj.ca/problem/ccc20j3
//CCC '20 J3 - Art

#include <bits/stdc++.h>
using namespace std;
// template <typename T>
// void print_vector(vector<T>& vec){
//     for (T& elem : vec) {
//         cout << elem << " ";
//     }
//     cout << endl;
// }
int main(){
    int n;
    string myinput;
    vector<int> leftlist;
    vector<int> rightlist;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> myinput;
        stringstream ss(myinput);
        string num1_str, num2_str;
        getline(ss, num1_str, ',');
        getline(ss, num2_str, ',');
        // size_t comma_pos = myinput.find(',');
        // string num1_str = myinput.substr(0, comma_pos);
        // string num2_str = myinput.substr(comma_pos + 1);
        int num1 = stoi(num1_str);
        int num2 = stoi(num2_str);
        leftlist.push_back(num1);
        rightlist.push_back(num2);
    }
    sort(leftlist.begin(), leftlist.end());
    sort(rightlist.begin(), rightlist.end());
    // print_vector(leftlist);
    // print_vector(rightlist);
    cout << leftlist[0]-1 << "," << rightlist[0]-1 << endl;
    cout << leftlist[n-1]+1 << "," << rightlist[n-1]+1 << endl;   
}