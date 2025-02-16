//https://dmoj.ca/problem/ccc23j2
//CCC '23 J2 - Chili Peppers

#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    int total = 0;
    string my_key;
    cin >> n;
    map<string, int> my_map = {
        {"Poblano", 1500},
        {"Mirasol", 6000},
        {"Serrano", 15500},
        {"Cayenne", 40000},
        {"Thai", 75000},
        {"Habanero", 125000}
    };

    for (int i = 0; i < n; i++){
        cin >> my_key;
        auto it = my_map.find(my_key);
        if (it != my_map.end()){
            total += it->second;
        }
    }

    cout << total << endl;

}
