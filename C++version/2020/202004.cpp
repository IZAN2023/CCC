#include <bits/stdc++.h>
using namespace std;

int main() {
    string my_text, my_input;
    getline(cin, my_text);
    getline(cin, my_input);

    bool found = false;
    int len = my_input.length();

    for (int i = 0; i < len; ++i) {
        string shifted_input = my_input.substr(i) + my_input.substr(0, i);

        if (my_text.find(shifted_input) != string::npos) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
