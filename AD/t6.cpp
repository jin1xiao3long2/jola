//贪心算法
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

//假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，
//其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。
//注意：
//总人数少于1100人。
//示例
//        输入:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
//输出:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


struct person {
    int h = 0;
    int k = 0;

    friend std::ostream &operator<<(std::ostream &os, const person &person) { //重载输出
        os << "[" << person.h << "," << person.k << "]";
        return os;
    }

    person(int h, int k) : h(h), k(k) {}  //构造函数
};

std::ostream &operator<<(std::ostream &os, const vector<person> &People) { //重载输出
    int num = 0;
    os << "[";
    for (auto const &p : People) {
        os << p;
        num++;
        if (num != People.size())
            os << ",";
    }
    os << "]";
    return os;
}

bool cmp(person &lhs, person &rhs) { //比较器, 用于排序. 相同h, k小的在前面, 不同h, h大的在前面
    if (lhs.h == rhs.h) {
        return lhs.k < rhs.k;
    }
    return lhs.h > rhs.h;
}

void greedy(const vector<person> &People, vector<person> &res) { //核心算法
    for (auto const &p : People) {  //遍历一次排好序的数据
        auto iter = res.begin();    //由于插入首位后,迭代器会失效,故每次都重新复制迭代其
        res.insert(iter + p.k, p);  //在指定位置插入数
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<person> People;
    vector<person> res;
    while (n--) {
        int h, k;
        cin >> h >> k;
        People.emplace_back(h, k); //获取数据
    }
    std::sort(People.begin(), People.end(), cmp); //利用比较器进行排序
    greedy(People, res); //进行贪心算法
    cout << res << endl;    //输出
    return 0;
}
