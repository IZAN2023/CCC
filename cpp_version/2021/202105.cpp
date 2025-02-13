#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    
    string input;
    vector<string> nptvec;
    for (int i = 0; i < n1; i++) {
        input = string(n2, 'B');
        nptvec.push_back(input);
    }
    
    int times;
    cin >> times;
    cin.get();
    vector<string> operations(times);
    for (int i = 0; i < times; i++) {
        getline(cin, operations[i]);
    }

    map<string, int> operation_count;
    for (const string& op : operations) {
        operation_count[op]++;
    }
    vector<string> filtered_operations;
    for (const auto& entry : operation_count) {
        if (entry.second % 2 == 1) {
            filtered_operations.push_back(entry.first);
        }
    }
    for (const string& change : filtered_operations) {
        auto opos = find(change.begin(), change.end(), ' ');
        int pos = distance(change.begin(), opos);
        
        if (change[0] == 'R') {
            int row = stoi(change.substr(pos + 1)) - 1;
            for (int m = 0; m < n2; m++) {
                nptvec[row][m] = (nptvec[row][m] == 'B') ? 'G' : 'B';
            }
        } else {
            int col = stoi(change.substr(pos + 1)) - 1;
            for (int mm = 0; mm < n1; mm++) {
                nptvec[mm][col] = (nptvec[mm][col] == 'B') ? 'G' : 'B';
            }
        }
    }
    int totalG = 0;
    for (int x = 0; x < n1; x++) {
        for (int y = 0; y < n2; y++) {
            if (nptvec[x][y] == 'G') {
                totalG++;
            }
        }
    }

    cout << totalG << endl;
    return 0;
}
