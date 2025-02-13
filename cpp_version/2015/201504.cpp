#include <bits/stdc++.h>
using namespace std;

void print_map(map<string, int>& m) {
    for (auto& elem : m) {
        cout << elem.first << " " << elem.second << endl;
    }
}

int main(){
    int n;
    string message; 


    map<string, int> start;
    map<string, int> result;
    int time = 0;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++){
        getline(cin, message);
        // int pos = message.find(' ');
        string action = message.substr(0, 1);
        string name = message.substr(2);
        if (action == "R") {
            start[name] = time;
            time++;
        } else if (action == "W" ) {
            time += stoi(name) - 1;
        } else if (action == "S") {
            if (result.find(name) == result.end()) {
                result[name] = time - start[name];
            } else {
                result[name] += time - start[name];
            }
            time++;
            start.erase(name);
        }
    }

    for (auto& elem : start) {
        result[elem.first] = -1;
    }
    // print_map(start);
    print_map(result);
    
}