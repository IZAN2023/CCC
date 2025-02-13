// CCC '18 J5 - Choose your own path
// https://dmoj.ca/problem/ccc18j5

// Canadian Computing Competition: 2018 Stage 1, Junior #5

// There is a genre of fiction called choose your own adventure books. 
// These books allow the reader to make choices for the characters which alters the outcome of the story.

// For example, after reading the first page of a book, the reader may be asked a choice, such as "Do you pick up the rock?" 
// If the reader answers "yes", they are directed to continue reading on page 47 , 
// and if they choose "no", they are directed to continue reading on page 18 . 
// On each of those pages, they have further choices, and so on, throughout the book. 
// Some pages do not have any choices, and thus these are the "ending" pages of that version of the story. 
// There may be many such ending pages in the book, some of which are good (e.g., the hero finds treasure) 
// and others which are not (e.g., the hero finds a leftover sandwich from 2001).

// You are the editor of one of these books, and you must examine two features of the choose your own adventure book:
//     ensure that every page can be reached – otherwise, there is no reason to pay to print a page which no one can ever read;
//     find the shortest path, so that readers will know what the shortest amount of time they need to finish one version of the story.

// Given a description of the book, examine these two features.

// Input Specification

// The first line of input contains N ( 1 ≤ N ≤ 10000 ) , the number of pages in the book. 
// Each of the next N lines contain an integer Mi ( 1 ≤ i ≤ N ; 0 ≤ Mi ≤ N ) , which is the number of different options from page i , 
// followed by Mi space-separated integers in the range from 1 to N , corresponding to each of the pages to go to next from page i . 
// It will also be the case M1 + M2 + ⋯ + MN is at most 10000 .

// If Mi = 0 , then page i is an ending page (i.e., there are no choices from that page). There will be at least one ending page in the book.

// Note that you always begin the book on page 1 .

// For 4 of the available 15 marks, N ≤ 100 , Mi ≤ 10 for 1 ≤ i ≤ N .
// For an additional 3 of the available 15 marks, the book is guaranteed to have no cycles.
// For an additional 4 of the available 15 marks, N ≤ 1000 , Mi ≤ 25 for 1 ≤ i ≤ N .

// Output Specification

// The output will be two lines. The first line will contain Y if all pages are reachable, and N otherwise.
// The last line will contain a non-negative integer K , which is the shortest path a reader can take while reading this book. There will always be a finite shortest path.

// input第一行n代表总页数
// 接下来n行，代表每页的情况，每行中第一个数字代表这一页有几个跳转选择（num_of_choice），然后接着的就是各跳转的目标页数
// 如果第一个数字为0，代表end
// 要判断是否能够到达每一页
// 也要找到最短的路径


#include <bits/stdc++.h>
using namespace std;
// 为方便调试，设计了打印map的函数
void print_vec(vector<int> v) {
    cout << "[";
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i != v.size() -1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
void print_map(map<int, vector<int>> m) {
    for(const pair<int, vector<int>>& elem : m){
        cout << elem.first << ": ";
        print_vec(elem.second);
    }
}




int main() {

    int n;
    cin >> n;

    // 设计一个map，key是页码，从第一页开始；value是改页码上的选择，即可以跳转到第几页，第0页即end
    // 写完后发现，其实用二维vector也可以达到类似效果，我脑子锈了...
    map<int, vector<int>> adventure;

    for(int i = 1; i < n + 1; i++){
        // 接受每行的第一个数字，代表本页有几个选择
        int num_of_choice;
        cin >> num_of_choice;
        if(num_of_choice == 0) {
            // 如果选择数量为0，即end，干脆就push一个 0 进去，以后碰到 0 就代表结局了
            adventure[i].push_back(0);
        } else {
            // 如果选择数量不为0，那么要用一个for，来cin接受可跳转的页数
            for(int j = 0; j < num_of_choice; j++) {
                int page;
                cin >> page;
                adventure[i].push_back(page);
            }
        }
    }

    // print_map(adventure);
    // 假如输入是这样：
    // 10
    // 1 10
    // 1 2
    // 2 3 4
    // 2 1 2
    // 5 4 6 7 2 10
    // 5 5 7 1 3 6
    // 2 5 4
    // 0
    // 4 2 6 9 8
    // 3 7 8 4

    // 那么最终则print这样的map
    // 1: [10]
    // 2: [2]
    // 3: [3, 4]
    // 4: [1, 2]
    // 5: [4, 6, 7, 2, 10]
    // 6: [5, 7, 1, 3, 6]
    // 7: [5, 4]
    // 8: [0]
    // 9: [2, 6, 9, 8]
    // 10: [7, 8, 4]

    // 接下来要进行搜索了。因为入口始终为 第1页，要以最快的算法判断是否所有页码都能被遍历到，同时还要判断到达end的最短路径距离
    // 此处 如果采用深度优先，效率肯定不高，因为每条路都必须走到底才能尝试下一条，假如走到end的那个选择放在最后，那必定要耗费太多的时间；
    // 所以广度优先是明智的选择，即 从第一页入口（第一层），然后第一页的每个选择都向下走一步（第二层），接着各条分支再向前进一步（第三层），直到所有页码都被遍历到，并且走到end，BFS就可以结束了。

    // 为了判断是否 “所有页码都被遍历到”、“走到end”， 我们要设计好判断条件。
    // 我们用一个set来记录所有遍历过的页码，set不会有重复数据，所以当set的长度 == n时，就说明 “所有页码都被遍历到” 了。

    // “走到end” 是很好判断的，遇到 0 就行了，但之前的每一步，要记录step，因为题目要求输出总步数；
    // 这里要利用一种“巧妙”的设计，我们设计一个 vector<int> distance ，它的下标代表 页码，初始值为无穷大，代表到达该页码的开销为无穷大；

    //因为要用到前面输入的各种数据，省得函数传来传去，这里我就直接在main里面写bfs了
    set<int> visited;
    vector<int> distance(n + 1, INT_MAX);  // 因为下标0用不上
    vector<int> step_hit_0;    // 每次撞到 0，我就记录一下step，第一条记录就是最短的step；


    // **** bfs 开始
    queue<int> q;

    q.push(1); // bfs入口是 第1页
    visited.insert(1);
    distance[1] = 1;

    while(!q.empty()){
        // 处理队列头部第一个元素
        int current_page = q.front();  
        q.pop();

        for(const int& choice : adventure[current_page]){
            if(choice == 0) {
                // 记录下每次到达0 的步数
                step_hit_0.push_back(distance[current_page]);
            } else if(distance[choice] == INT_MAX) {
                distance[choice] = distance[current_page] + 1;
                q.push(choice);
                visited.insert(choice);
            }
            // 如果距离无穷大，说明此页从未被访问过
            // 那么就记录到达这个点的距离（当前页码的距离+1），然后放入q，准备下一步继续探索，并且在visited中记录

            // 换言之，如果距离不是无穷大，说明曾经访问过，那么啥都不用做，直接跳过就行了
            // 到这里你会发现，visited用不用set，其实不重要，vector也可以，因为我们压根就不会重复访问某一页；
        }
    }

    // **** bfs 到此结束

    if (visited.size() == n) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }

    cout << step_hit_0[0] << endl;

}