#include <bits/stdc++.h>
using namespace std;

// Suppose that you have n pieces of pie, and k people who are lined up for pieces of pie. 
// All n pieces of pie will be given out. Each person will get at least one piece of pie, but mathematicians are a bit greedy at times. 
// So, they always get at least as many pieces of pie as the person in front of them.

// For example, if you have 8 pieces of pie and 4 people in line, you could give out pieces of pie in the following five ways 
// (with the first person in line being the first number in the list): [1, 1, 1, 5], [1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3], [2, 2, 2, 2].

// Notice that if k = n , there is only one way to give out the pieces of pie: every person gets exactly one piece. 
// Also, if k = 1 , there is only one way to give out the pieces of pie: that single person gets all the pieces.

// Write a program that determines the number of ways that the pieces of pie can be given out.

// 这是一个动态规划思想 + 递归实现的例子
// 动态规划：
// 题目其实只关心分配方案，并不关心在某个方案中，饼多的那个分给了谁，这就好办了，也就是说分配方案与具体的人无关



// 根据题意，为了接下来能够尽可能遍历到所有的分配方案，我们把分配规则写的更程式化一些：
//    当n <= k 时（饼少人多），只有 1 种方案
//    当n > k 时（饼多人少），定分配规则：后面的人得到的饼的数量 必须>= 前一个人得到的饼的数量，这样就可以确保算方案的唯一性；



int dp(int pie_left, int people_left, int min_value) {
    // 当只有一个人时，所有饼干都归他
    if(people_left == 1) {
        return 1;
    }
    // 当只剩下一块饼干时，就只有一种分配方案了
    if(pie_left == 1) {
        return 1;
    }
    int count = 0;
    //第一个人至少有一块饼

    // 状态转移
    // 假设目前正在 dp(100块饼, 30个人, 1) ，那么只需要看第一个人拿 1、2、3 块饼的情况，分别是dp(99, 29, 1) + dp(98, 29, 2) + dp(97, 29, 3)
    // 因为如果第一个人拿4块饼，后面就必然有人拿到的饼小于4，这就违反了我们定的 “分配规则”
    for(int i = min_value; i <= pie_left / people_left; i++) {
        count += dp(pie_left - i, people_left -1, i);
    }

    return count;
}

int main(){
    int n;   // pie
    int k;   // people

    cin >> n;
    cin >> k;
    int result;
    if(n <= k) {
        result = 1;   // 饼少人多，只有 1 种方案
    } else {
        result = dp(n, k, 1);
    }

    cout << result << endl;
    return 0;
}