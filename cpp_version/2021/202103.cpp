//https://dmoj.ca/problem/ccc21j3
//CCC '21 J3 - Secret Instructions

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
    vector<int> my_vector;
    int my_num;
    int my3num;
    string laststate;
    while (true){
        cin >> my_num;
        if (my_num == 99999){
            break;
        }
        else{
            my_vector.push_back(my_num);    
        }
    }
    // print_vector(my_vector);
    int vector_n = my_vector.size();
    //也可以直接在for里面使用my_vector.size()
    for (int i = 0; i < vector_n; i++){
        if (my_vector[i] == 99999){
            break;
        }
        //进入判断前面两个数字
        else if ((my_vector[i] / 10000 + (my_vector[i] / 1000) % 10) % 2 != 0){
            my3num = my_vector[i] % 10000 % 1000;
            cout << "left " << my3num << endl;
            laststate = "left ";
        }
        else if (my_vector[i]/1000 == 0){
            cout << laststate << my_vector[i] << endl;
        }
        else{
            my3num = my_vector[i] % 10000 % 1000;
            cout << "right " << my3num << endl;
            laststate = "right ";
        }
    }
    
}