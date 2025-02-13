#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_vector(vector<T>& vec){
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1){
            cout << ",";
        }
    }
    cout << endl;
}
int main(){
    int n;
    vector<int> daylist = {0, 0, 0, 0, 0};
    vector<int> anslist;
    string yorpoint;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> yorpoint;
        for (int j = 0; j < 5; j++){
            if (yorpoint[j] == 'Y'){
                daylist[j]+=1;
            }
        } 
    }
    auto max_num = std::max_element(daylist.begin(), daylist.end());
    // cout << *max_num << endl;
    // print_vector(daylist);
    for (int k = 0; k < 5; k++){
        if (daylist[k] == *max_num){
            anslist.push_back(k+1);
        }
    }
    print_vector(anslist);

}