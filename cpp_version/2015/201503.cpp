//https://dmoj.ca/problem/ccc15j3
//CCC '15 J3 - Rövarspråket

#include <bits/stdc++.h>
using namespace std;
int main(){
    string letterlist = "abcdefghijklmnopqrstuvwxyz";
    // string letterlist_y = "aeiou";
    string letter_list = "bcdfghjklmnpqrstvwxyz";
    string my_input;
    cin >> my_input;
    string my_ans;
    for (size_t i = 0; i < my_input.size(); i++){
        if (letter_list.find(my_input[i]) != string::npos){
            int pos = letterlist.find(my_input[i]);
            int pos2 = letter_list.find(my_input[i]);
            if (pos <= 2){
                if (my_input[i] == 'z'){
                    my_ans += my_input[i];
                    my_ans += 'a';
                    my_ans += "z";
                }
                else{
                    my_ans += my_input[i];
                    my_ans += 'a';
                    my_ans += letter_list[pos2 + 1];
                }
            }
            else if(pos > 2 && pos <= 6){
                if (my_input[i] == 'z'){
                    my_ans += my_input[i];
                    my_ans += 'e';
                    my_ans += "z";
                }
                else{
                    my_ans += my_input[i];
                    my_ans += 'e';
                    my_ans += letter_list[pos2 + 1];
                }
            }
            else if(pos > 6 && pos <= 11){
                if (my_input[i] == 'z'){
                    my_ans += my_input[i];
                    my_ans += 'i';
                    my_ans += "z";
                }
                else{
                    my_ans += my_input[i];
                    my_ans += 'i';
                    my_ans += letter_list[pos2 + 1];
                }
            }
            else if(pos > 11 && pos <= 17){
                if (my_input[i] == 'z'){
                    my_ans += my_input[i];
                    my_ans += 'o';
                    my_ans += "z";
                }
                else{
                    my_ans += my_input[i];
                    my_ans += 'o';
                    my_ans += letter_list[pos2 + 1];
                }
            }
            else{
                if (my_input[i] == 'z'){
                    my_ans += my_input[i];
                    my_ans += 'u';
                    my_ans += "z";
                }
                else{
                    my_ans += my_input[i];
                    my_ans += 'u';
                    my_ans += letter_list[pos2 + 1];
                }
            } 
        }
        else{
            my_ans += my_input[i];
        }
    }
    cout << my_ans << endl;
}