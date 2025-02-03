#include <bits/stdc++.h>
using namespace std;
//普通vector
vector<int> a = {};
//二维vector
vector<vector<int>> b = {};
//打印vector
template <typename T>
void print_vec(const vector<T>& v) { //可以用引用（&），如果要改vector就不要使用
    for (const T& elem: v) {
        cout << elem << " ";
    }
    cout << endl;
}
//string to int
string str = "259";
int c = stoi(str);
//无限大1
numeric_limits<int>::max();
//无限大2
INT_MAX();
//大小
str.size();
//求和
accumulate(dp.begin(), dp.end(), 0);
//string 和 vector 都可以使用push_back
string str1;
vector<string> strvec;
char str2;
str1.push_back(str2);
strvec.push_back(str2);
//如果 c 在字符串 str_1 中不存在，则返回 true
str_1.find(c) == string::npos;
//sort语句
sort(my_list.begin(), my_list.end());
 //反向迭代器，因为出来的大的在后，小的在前。
auto it = myset.rbegin();
 //给it移动2步到倒数第三个。
advance(it, 2);
//删除语句
line1.erase(remove(line1.begin(), line1.end(), ' '), line1.end());
//pos语句
int pos = myinput.find(',');
//取得左边
string left = myinput.substr(0,pos);
//int转换string
to_string(total);
//清除内容
string e = "abcdefb";
e.clear();
//保证结尾自带小数点一位
cout << fixed << setprecision(1);
//反转元素
reverse(list2.begin(), list2.end());

//容易忘记
cin >> a;
//重要
cin.get();
//才能
getline(cin, b);