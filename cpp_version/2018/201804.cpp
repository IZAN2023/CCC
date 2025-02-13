#include <bits/stdc++.h>
using namespace std;
// template <typename T>
// void print_vector(vector<T>& vec){
//     for (T& elem : vec){
//         cout << fixed << setprecision(1);
//         cout << elem << ",";
//     }
// }
int main(){
    int n;
    cin >> n;
    int num;
    vector<int> adresslist;
    vector<double> rangelist;
    double range = 0.0;
    for (int i = 0; i < n; i++){
        cin >> num;
        adresslist.push_back(num);
    }
    // print_vector(adresslist);
    sort(adresslist.begin(), adresslist.end());
    // print_vector(adresslist);
    for (int j = 0; j < adresslist.size()-2; j++){
        range = (adresslist[j+2] - adresslist[j]) / 2.0;
        // cout << range << endl;
        rangelist.push_back(range);
    }
    sort(rangelist.begin(), rangelist.end());
    cout << fixed << setprecision(1);
    cout << rangelist[0] << endl;
}
