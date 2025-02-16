//https://dmoj.ca/problem/ccc18j3
//CCC '18 J3 - Are we there yet?

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << 0 << " " << a << " " << a+b << " " << a+b+c << " " << a+b+c+d << endl;
    cout << a << " " << 0 << " " << b << " " << b+c << " " << b+c+d << endl;
    cout << a+b << " " << b << " " << 0 << " " << c << " " << c+d << endl;
    cout << a+b+c << " " << b+c << " " << c << " " << 0 << " " << d << endl;
    cout << a+b+c+d << " " << b+c+d << " " << c+d << " " << d << " " << 0 << endl;
}