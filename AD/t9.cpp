//回溯算法

#include <iostream>
#include <vector>

//假设有从 1 到 N 的 N 个整数，如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N)
//满足如下两个条件中的一个，我们就称这个数组为一个优美的排列。条件：
//第 i 位的数字能被 i 整除
//        i 能被第 i 位上的数字整除
//        现在给定一个整数 N，请问可以构造多少个优美的排列？
//示例1:
//输入: 2
//输出: 2
//解释:
//第 1 个优美的排列是 [1, 2]:
//第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
//        第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除
//
//        第 2 个优美的排列是 [2, 1]:
//第 1 个位置（i=1）上的数字是2，2能被 i（i=1）整除
//        第 2 个位置（i=2）上的数字是1，i（i=2）能被 1 整除
//        说明:
//
//N 是一个正整数，并且不会超过15

using std::cin;
using std::cout;
using std::endl;
using std::vector;

//std::ostream &operator<<(std::ostream &os, const vector<int> &V) {
//    for (auto const &e: V)
//        os << e << " ";
//    return os;
//}

bool suitable(int num1, int num2) {  //判断是否达到条件
    return (num1 % num2 == 0 || num2 % num1 == 0);
}

void DFS(vector<bool> &visited, int pos, int n, int &res) {
    if (pos > n) {
        res += 1;
//        cout << v << endl;
        return;
    }
    for (auto i = 1; i <= n; i++) {
//        cout << "pos: " << pos << " i: " << i << " result << " << devide(pos, i) << endl;
        if (!visited[i] && suitable(pos, i)) {
            visited[i] = true; //记录使用过的数据
//            v.push_back(i);
//            cout << v << endl;
            DFS(visited, pos + 1, n, res); //针对剩下的再次使用算法
//            v.pop_back();
            visited[i] = false;  //回溯
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<bool> visited;
//    vector<int> v;
    int res = 0;
    visited.assign(n + 1, false);
    DFS(visited, 1, n, res);
    cout << res << endl;
    return 0;
}

