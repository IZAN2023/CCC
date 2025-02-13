// CCC '19 J5 - Rule of Three
// Canadian Computing Competition: 2019 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc19j5

// 这道题先要知道如何替换字符串中的某些字符，例如：
// 我们要把“123AA456”中的 AA 替换成 BBB ，得到“123BBB456”
    // string test = "123AA456";
    // size_t pos = test.find("AA");
    // test.replace(pos, 2, "BBB");
    // 详见C++参考库
    // https://learn.microsoft.com/zh-cn/cpp/standard-library/basic-string-class?view=msvc-170
// 为方便编码，我们用一个pair来存储要替换的字符串，pair中的first代表源，pair中的second代表目标
    // pair<string, string> rule = {"AA", "BBB"};


// 备注：此解法可以拿到7分，当bfs层级不超过7时，性能尚可接受
// 但是对于更大的bfs层级，需要优化剪枝，目前没有找到非常合适的剪枝方法
// 试了一下，靠长度判断来剪枝，可以提高1分，这个纯属瞎猜，谈不上算法，详见下面代码中的备注


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<string, string>> rules(3);
    int step;
    string initial, final;

    // 前三行输入转换规则，放到pair中，以方便取用
    for(int i = 0; i < 3; i++){
        cin >> rules[i].first >> rules[i].second;
    }
    cin >> step;
    cin >> initial;
    cin >> final;

    // 设计好 visited 数据结构，这个visited就是题目最终要求输出的路径
    // tuple中的第一个int是rule number，第二个int是postion，string是按规则替换后输出的字符串
    // 由于要为每条分支记录路径，所以这里的visited不能全局设置，必须跟随每一次push来记录
    // 所以 visited 要放入queue中，也就是说每一次push的时候，都把此刻的visited记录在queue里

    // vector<tuple<int, int, string>> visited;  // rule, pos, str_after_replaced
    
    // **** bfs ****
    queue<tuple<int, string, vector<tuple<int, int, string>>>> q;   // <step_num, current_string, visited>
    
    // 第一次手动 push
    // 针对每个规则，在initial字符串中查找匹配，所有可能的匹配，都要做replace，并且push到queue中
    for(int i = 0; i < 3; i++) {
        size_t pos = initial.find(rules[i].first);
        while(pos != string::npos) {
            // 因为initial要多次调用，而C++ string的replace是直接修改原字符串的，所以这里要先copy给新字符串，然后对新字符串进行replace
            string new_str = initial;
            new_str.replace(pos, rules[i].first.size(), rules[i].second);
            // 手动push，step_num为1，代表第一次push；visited 路径方面，rule number和position number，题目都要求从1开始（不是0开始），因此要+1
            q.push({1, new_str, {{i + 1, pos + 1, new_str}}});

            // 针对这个规则，继续查找有没有其他匹配的可能，有的话继续while
            pos = initial.find(rules[i].first, pos + 1);
        }
    }

    while(!q.empty()){
        // bfs的pop，取队列头，得到当前的step number、当前的string、path
        auto [step_current, str_current, visited_current] = q.front();
        q.pop();

        // 当步数到达目标步数，并且字符串匹配的时候，打印输出visited
        if(step_current == step && str_current == final) {
            for(const auto& elem: visited_current){
                auto[rule, pos, str] = elem;
                cout << rule << " " << pos << " " << str << endl;
            }
            break;
        }
        // 当步数到达目标步数，字符串不匹配，没必要继续bfs了，直接continue
        else if (step_current == step) {
            continue;
        }
        // 当step超过6的时候，性能明显下降，这里做点剪枝，但这个剪枝纯属瞎猜，不过可以多拿一分
        else if(step_current > 6 && str_current.size() > final.size() * 2) {
            continue;
        }

        // 继续bfs，遍历三个规则，查找所有可能的匹配，push queue
        for(int i = 0; i < 3; i++) {
            size_t pos = str_current.find(rules[i].first);
            while(pos != string::npos) {
                string new_str = str_current;
                new_str.replace(pos, rules[i].first.size(), rules[i].second);
                // visited 也要和上面的new_str一样处理，每一次push，都单独记录自己的 visited
                auto new_visited = visited_current;
                new_visited.push_back({i + 1, pos + 1, new_str});
                q.push({step_current + 1, new_str, new_visited});

                pos = str_current.find(rules[i].first, pos + 1);
            }
        }
    }

    return 0;
}