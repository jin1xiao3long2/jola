#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int time = 0;

std::ostream &operator<<(std::ostream &out, vector<string> v) { //重载输出vector<string>
    out << "[ ";
    auto size = v.size();
    int start = 1;
    for (auto const &e: v) {
        out << "\"" << e << "\"";
        if (start < size)
            out << ", ";
        start++;
    }
    out << " ]";
    return out;
}

std::ostream &operator<<(std::ostream &out, vector<vector<string>> V) { //重载输出vector<vector<string>>
    out << "[ ";
    auto size = V.size();
    int start = 1;
    for (auto const &e : V) {
        out << e;
        if (start < size)
            out << ", ";
        start++;
    }
    out << " ]";
    return out;
}

//判断是否是回文数,若先切割字符串再传参会有复制的过程从而降低效率, 故直接传const引用, 用标记为来判断是否子串为回文
bool is_plalin(const std::string &s, int begin, int end) {
    while (begin < end) {  //此处特殊情况为, 若begin和end相等,则直接返回true
        if (s.at(begin) != s.at(end))
            return false;
        end--;
        begin++;
    }
    return true;
}

//核心算法
void look_back_algo(vector<vector<string>> &V, vector<string> &v, int begin, const std::string &str) {
    time++;
    if (begin == str.size()) { //如果已经到末尾了, 则直接插入
        V.push_back(v);
        return;
    }
    for (auto i = begin; i < str.size(); i++) { //从最开始开始判断
        if (!is_plalin(str, begin, i))          //如果该子串不是回文, 则跳过该次迭代
            continue;
        v.push_back(str.substr(begin, i + 1 - begin)); //存入字串
        look_back_algo(V, v, i + 1, str);  //处理剩下的字串
        v.pop_back(); //回溯
    }
}

int main() {
    vector<vector<string>> V;
    vector<string> v;
    string str;
    cin >> str;  //获取字符串
    look_back_algo(V, v, 0, str); //获得结果
    cout << V; //输出获得的答案
    cout << time;
    return 0;
}
