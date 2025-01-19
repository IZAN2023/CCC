#include <iostream>
using namespace std;
int main(){
    int delivered;
    int collisions;
    int score;
    cin >> delivered;
    cin >> collisions;
    if (delivered > collisions){
        score = 500 + delivered*50 - collisions*10;
    }
    else {
        score = delivered*50 - collisions*10;
    }
    cout << score << endl;
}