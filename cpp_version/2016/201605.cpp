//https://dmoj.ca/problem/ccc16s2
//CCC '16 S2 - Tandem Bicycle

#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_vector(vector<T>& vec){
    for (T& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}
int main(){
    int question;
    int n;
    int total = 0;
    cin >> question;
    cin >> n;
    cin.get();
    string a1;
    string a2;
    vector<int> list1;
    vector<int> list2;
    getline(cin, a1);
    getline(cin, a2);
    istringstream stream(a1);
    int number;
    while (stream >> number) { 
        list1.push_back(number);
    }
    istringstream stream2(a2);
    int numbers;
    while (stream2 >> number) { 
        list2.push_back(number);
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    reverse(list2.begin(), list2.end());
    // print_vector(list1);
    // print_vector(list2);
    if (question == 1){
        reverse(list2.begin(), list2.end());
        for (int k = 0; k < n; k++){
            if (list1[k] >= list2[k]){
                total += list1[k];
            }
            else{
                total += list2[k];
            }
        }
    }
    else {
        for (int p = 0; p < n; p++){
            if (list1[p] == list2[p]){
                int first = list1[p];
                list1.erase(list1.begin() + p);
                list1.insert(list1.begin(), first);
            }
        }
        for (int o = 0; o < n; o++){
            if (list1[o] > list2[o]){
                total += list1[o];
            }
            else{
                total += list2[o];
            }
        }
    }
    cout << total << endl;
}