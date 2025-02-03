#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num;
    vector<int> adress;
    vector<double> rangevec;
    double range = 0.0;
    for (int i = 0; i <n; i++){
        cin >> num;
        adress.push_back(num);
    }
    sort(adress.begin(),adress.end());
    for (int j=0; j < adress.size()-2; j++){
        range = (adress[j+2] - adress[j])/2.0;
        rangevec.push_back(range);
    }
    sort(rangevec.begin(), rangevec.end());
    cout << fixed << setprecision(1);
    cout << rangevec[0] << endl;
}