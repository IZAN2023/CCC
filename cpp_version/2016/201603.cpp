#include <bits/stdc++.h>
using namespace std;
int main(){
    string my_input;
    cin >> my_input;
    int max_len = 1;
    int n = my_input.size();
    int current_len;
    for (int i = 0; i < n; i++){
        int l = i, r = i;
        while (l >= 0 && r < n && my_input[l] == my_input[r]){
            current_len = r - l+1;
            if(current_len > max_len){
                max_len = current_len;
            }
            l--;
            r++;
        }

        int l_n = i, r_n = i+1;
        while (l_n >= 0 && r_n < n && my_input[l_n] == my_input[r_n]){
            current_len = r_n-l_n+1;
            if(current_len > max_len){
                max_len = current_len;
            }
            l_n--;
            r_n++;
        }
    }
    cout << max_len << endl;
}