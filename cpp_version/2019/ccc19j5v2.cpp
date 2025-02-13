// CCC '19 J5 - Rule of Three
// Canadian Computing Competition: 2019 Stage 1, Junior #5
// https://dmoj.ca/problem/ccc19j5

// 在v1解法基础上，试图优化
// 因为v1解法的性能差是因为bfs层级太深引起的，所以这里采用双向BFS来优化
// 所谓双向BFS，就是从两头分别做bfs，例如：
// 假设测试数据要求step为12，那么从initial做6层bfs，再从final反向做6层bfs，把它们bfs得出的分支结果做对比，找到相同的以后，再拼接路径

// 此解法可以将得分改进至15分，但是依旧拿不到官方放出的30分总分，由于看不到官方额外定义的15分的测试数据，所以目前只能优化到这一步了。

#include <bits/stdc++.h>
using namespace std;

// 改用结构体来push queue，和v1解法中的tuple是类似的
struct State {
    int step;
    string str;
    vector<tuple<int, int, string>> path;  // rule, pos, str_after_replace
};

int main() {
    vector<pair<string, string>> rules(3);
    int step;
    string initial, final;

    // 前三行输入转换规则
    for(int i = 0; i < 3; i++){
        cin >> rules[i].first >> rules[i].second;
    }
    cin >> step;
    cin >> initial;
    cin >> final;
    
    // f_result用于记录forward_queue算出的各分支结果和path的对应表
    map<string, vector<tuple<int, int, string>>> f_result;

    // 定义两个queue，一个从七点推，一个从终点推
    queue<State> forward_queue, backward_queue;

    // 第一条手动push的数据改成step 0，简化v1
    forward_queue.push({0, initial, {}});
    backward_queue.push({0, final, {}});

    // 算一下forward和backward分别要几步，当总step为偶数时，正好各一半，当总step为奇数时，让backward多算一步
    int f_step, b_step;
    if(step % 2 == 0) {
        f_step = step / 2;
        b_step = step / 2;
    } else {
        f_step = step / 2;
        b_step = step / 2 + 1;
    }

    // 开始从initial的bfs
    while(!forward_queue.empty()){
        auto [step_current, str_current, path_current] = forward_queue.front();
        forward_queue.pop();
        // 到达规定步数时，记下所有结果
        if(step_current == f_step) {
            f_result[str_current] = path_current;
            continue;
        }

        for(int i = 0; i < 3; i++) {
            size_t pos = str_current.find(rules[i].first);
            while(pos != string::npos) {
                string new_str = str_current;
                new_str.replace(pos, rules[i].first.size(), rules[i].second);
                auto new_path = path_current;
                new_path.push_back({i + 1, pos + 1, new_str});
                forward_queue.push({step_current + 1, new_str, new_path});
                pos = str_current.find(rules[i].first, pos + 1);
            }
        }
    }

    // 开始从result的bfs
    while(!backward_queue.empty()){
        auto [step_current, str_current, path_current] = backward_queue.front();
        backward_queue.pop();

        // 当到达规定步数时，和f_result中的记录进行对比，发现匹配则输出结果
        // 两边的path需要不同处理，forward方向的正常输出，backward方向的反向输出
        if(step_current == b_step) {
            if(f_result.find(str_current) != f_result.end()){
                for (const auto& [rule, pos, str] : f_result[str_current]) {
                    cout << rule << " " << pos << " " << str << endl;
                }
                for (size_t i = 0; i < path_current.size(); i++) {
                    auto [rule, pos, str] = path_current[path_current.size() - i - 1];
                    cout << rule << " " << pos << " " << str << endl;
                }
                break;
            }else {
                continue;
            }
        }

        for(int i = 0; i < 3; i++) {
            size_t pos = str_current.find(rules[i].second);
            while(pos != string::npos) {
                string new_str = str_current;
                new_str.replace(pos, rules[i].second.size(), rules[i].first);
                auto new_path = path_current;
                // 这里记录路径的时候，string要记录上一步的string（记current，而不是new），以便将来输出的时候造成是从initial推过来的“假象”
                new_path.push_back({i + 1, pos + 1, str_current});
                backward_queue.push({step_current + 1, new_str, new_path});
                pos = str_current.find(rules[i].second, pos + 1);
            }
        }
    }

    return 0;
}