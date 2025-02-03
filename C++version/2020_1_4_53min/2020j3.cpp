#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> leftlist;
    vector<int> rightlist;
    for (int i = 0; i< n; i++){
        string myinput;
        cin >> myinput;
        int pos = myinput.find(',');
        string left = myinput.substr(0,pos);
        string right = myinput.substr(pos+1);
        int leftn = stoi(left);
        int rightn = stoi(right);
        leftlist.push_back(leftn);
        rightlist.push_back(rightn);
    }
    sort(leftlist.begin(), leftlist.end());
    sort(rightlist.begin(), rightlist.end());
    cout << leftlist[0]-1 << ',' << rightlist[0]-1 << endl;
    cout << leftlist[n-1]+1 << ',' << rightlist[n-1]+1;
}