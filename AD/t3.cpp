#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

struct Section {  //结构体,用于储存区间的信息
    int begin = 0;
    int end = 0;

    Section() = default;
    Section(int ibegin, int iend) : begin(ibegin), end(iend) {}
    Section(const Section &obj) : begin(obj.begin), end(obj.end) {}
};

bool cmp(Section lhs, Section rhs) {  //排序所需要的函数
    return lhs.end < rhs.end;
}

int greedy(const vector<Section> &v) {
    if (v.empty())  //若无数据直接返回0
        return 0;
    int res = 1;    //最开始可用的区间为1
    auto now_end = v.at(0).end; //以第一个区间的末尾为计算的总区间的末尾开始
    for (auto e : v) {
        int begin = e.begin;  //记录区间的左临界点
        if (begin >= now_end) { //若该点比总区间的末尾大, 则该区间则可以进入到总区间的计算
            now_end = e.end;    //记录下个
            res++;              //记录可用区间的个数
        }
    }
    return v.size() - res;      //返回不可用区间的个数
}

int main() {
    vector<Section> v = {};
    v.emplace_back(1, 2);
    v.emplace_back(2, 3);
    v.emplace_back(3, 4);
    v.emplace_back(1, 4);  //初始化区间
    std::sort(v.begin(), v.end(), cmp); //排序区间
    auto res = greedy(v);   //进行算法
    cout << res << endl;
    return 0;
}
