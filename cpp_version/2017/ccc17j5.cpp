// https://dmoj.ca/problem/ccc17s3
// Canadian Computing Competition: 2017 Stage 1, Junior #5, Senior #3

// Input Specification
// The first line will contain the integer N ( 2 ≤ N ≤ 1 000 000 ) .
// The second line will contain N space-separated integers L1, L2, …, Ln ( 1 ≤ Li ≤ 2000 ).

// For 5 of the 15 available marks, N ≤ 100 .
// For an additional 4 of the 15 available marks, N ≤ 1 000 .
// For an additional 3 of the 15 available marks, N ≤ 100 000 .


// 目标首先 是要做longest fence，然后计算达到longest fence时，height有几种可能

// 分析：
// 最直观的做法是弄一个数组，记录下所有木板的长度，然后用双指针遍历，但这种方式在这道题可能会遇见性能问题
// 因为题目说了，要拿满15分，必须处理 N ≤ 100000 条记录，遍历这么庞大的数据量，开销小不了
// 而每条记录的取值范围在这个题目中看起来，却不大，1 ≤ Li ≤ 2000
// 那么我们可以换个思路，我们设计一个“索引数组”，即用数组的下标来代表输入的length，下标对应的值来代表length出现的频率（出现几次）
// 例如：v[1000] = 10, 代表length为1000的记录，总共有10条

// 我们将这种设计思想称作“索引数组”，这样就大幅提升了性能。

// 之所以选择这种设计，是根据题意来的，关于length的记录有很多条，但是lenth的数值变化不大，而且需求中只关心记录的数量（不care先后顺序），
// 那么就可以把length本身当做数组的索引，用数组的内容记录出现的次数。这样就用一个相对小的数组，记录了大量的“内容”。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int length;

    vector<int> height_of_1_board(2001, 0);   // 初始化一个名为height_of_board的数组，下标0用不上，而下标2000需要使用，所以数组长度定为2001，元素初始值为0
    for (int i = 0; i < n; i++) {
        cin >> length;
        height_of_1_board[length]++;           // 例如收到一个20的输入时，将freq[20]的内容+1，代表收到了一个20的length
    }

    vector<int> height_of_2_board(4001, 0);     // 用这个数组来统计任意两个length相加能得到的总长度出现的频率（4001的考量和2001一样，防止有板子正好长度为2000）

    for (int i = 1; i < 2001; i++) {
        if (height_of_1_board[i] == 0) {        // 如果某个length出现的频率为0，说明没有这个规格的board，本次循环就忽略
            continue;
        }
        for (int j = i; j < 2001; j++) {       // i为第一块木板的长度，j为第二块木板的长度，挨个搭伙拼一遍
            if (height_of_1_board[j] == 0){
                continue;
            }
            int freqency;
            if (i == j) {
                freqency = height_of_1_board[i] / 2;    // 两块长度相同的木板拼一起，这样的总高度能出现的 次数 为 木板数量 的1/2
            } else {
                freqency = min(height_of_1_board[i], height_of_1_board[j]);  // 两块长度不同的木板拼一起，这样的总高度能出现的 次数 为 数量少的那块木板的数量
            }
            height_of_2_board[i + j] += freqency;
        }
    }

    // 直接用max_element找到最大值（出现次数最高的次数），max_element返回的是一个iterator，需要用*取出它的值
    // 因为“The length of the fence is the number of boards used to make it”，所以max_fence_length就是这个值
    int max_fence_length = *max_element(height_of_2_board.begin(), height_of_2_board.end());

    int count = 0;
    // 要算出现几次，只能遍历了，这个没有现成的函数方法
    for(const int& elem: height_of_2_board) {
        if(elem == max_fence_length) {
            count++;
        }
    }

    cout << max_fence_length << " " << count << endl;
    return 0;
}