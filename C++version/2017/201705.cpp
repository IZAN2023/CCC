#include <bits/stdc++.h>
using namespace std;
int MAX_L = 4000;
int main() {
    int n;
    cin >> n;
    vector<int> freq(2000, 0);
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        freq[length]++;
    }
    vector<int> dp(MAX_L, 0);
    int maxH = 0;
    int count = 0;    
    for (int x = 1; x <= 2000; x++) {
        if (freq[x] == 0) {
            continue;
        }
        for (int y = x; y <= 2000; y++) {
            if (freq[y] == 0){
                continue;
            } 
            int length = x + y;
            int pairs = (x == y) ? freq[x] / 2 : min(freq[x], freq[y]); 
            dp[length] += pairs;
        }
    }
    for (int i = 2; i < MAX_L; i++) {
        if (dp[i] > maxH) {
            maxH = dp[i];
            count = 1;
        } 
        else if (dp[i] == maxH) {
            count++;
        }
    }
    cout << maxH << " " << count << endl;
    return 0;
}
