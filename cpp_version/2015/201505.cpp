#include <bits/stdc++.h>
using namespace std;
int total = 0;
void find_distributions(int pie_left, int people_left, vector<int>& distribution, int min_pie) {
    if (pie_left == 0 && people_left == 0) {
        total++;
        // for (int i = 0; i < distribution.size(); i++) {
        //     cout << distribution[i] << " ";
        // }
        // cout << endl;
        return;
    }
    if (pie_left <= 0 || people_left <= 0) {
        return;
    }
    for (int i = min_pie; i <= pie_left; i++) {
        distribution.push_back(i); 
        find_distributions(pie_left - i, people_left - 1, distribution, i); 
        distribution.pop_back(); 
    }
}

int main(){
    int pie;
    int mathpeople;
    vector<int> pielist;
    cin >> pie;
    cin >> mathpeople;
    vector<int> distribution;
    find_distributions(pie, mathpeople, distribution, 1);

    cout << total << endl;
    return 0;
    // for (int i = 0; i < mathpeople; i++){
    //     if (i != mathpeople-1){
    //         pielist.push_back(1);
    //     }
    //     else{
    //         pielist.push_back(pie - (mathpeople-1));
    //         total++;
    //     }
    // }
    // print_vec(pielist);
    // while(true){
    //     if (pie % mathpeople ==0){
    //         if ((pielist[mathpeople-1] == pielist[mathpeople-2]) && (pielist[0] == pielist[1])){
    //             break;
    //         }
    //         else{
    //             for (int j = mathpeople-1; j >= 0; j--){
    //                 print_vec(pielist);
    //                 if ((pielist[mathpeople-1] == pielist[mathpeople-2]) && (pielist[0] == pielist[1])){
    //                     break;
    //                 }
    //                 pielist[j]++;
    //                 pielist[mathpeople -1]--;
    //                 if (j == mathpeople -1){
    //                     continue;
    //                 }
    //                 else{
    //                     total++;
    //                 }

    //             }
    //         }
    //     }
    //     else{
    //         if (pielist[mathpeople-pie%mathpeople] == pielist[mathpeople-1]){
    //             break;
    //         }
    //         else{
    //             for (int j = mathpeople-1; j >= 0; j--){
    //                 if (pielist[mathpeople-pie%mathpeople] == pielist[mathpeople-1]){
    //                     break;
    //                 }
    //                 pielist[j]++;
    //                 pielist[mathpeople -1]--;
    //                 if (j == mathpeople -1){
    //                     continue;
    //                 }
    //                 else{
    //                     total++;
    //                 }
    //             }
    //         }
    //     }
    // }
    // print_vec(pielist);
    // cout << total << endl;
}