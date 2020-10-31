//分治算法

#include <iostream>
#include <vector>

//对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：
//对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。
//那么数组 A 是漂亮数组。
//给定 N，返回任意漂亮数组 A（保证存在一个）。
//
//示例 1：
//输入：4
//输出：[2,1,4,3]
//示例 2：
//输入：5
//输出：[3,1,2,5,4]
//
//提示：
//1 <= N <= 1000

using std::cin;
using std::cout;
using std::endl;
using std::vector;


std::ostream &operator<<(std::ostream &os, const vector<int> &V) {
    os << "[";
    int num = 0, size = V.size();
    for (auto const &e : V) {
        os << e;
        num++;
        if (num != size)
            os << ",";
    }

    os << "]";
    return os;
}


void divide_and_conquer(vector<int> &V, int begin, int end) {
    if (begin == end) //如果没有元素, 直接返回
        return;
    vector<int> S;    //临时储存的容器
    for (auto i = begin; i <= end; i += 2)
        S.push_back(V[i]);  //每2个做一个分割, 储存在临时容器的前侧
    for (auto i = begin + 1; i <= end; i += 2)
        S.push_back(V[i]);  //每2个做一个分割, 储存在临时容器的后侧
    for (auto i = begin; i <= end; i++)
        V.at(i) = S.at(i - begin);   //替换

    int mid = (begin + end) / 2;                   //分成两部分去修改
    divide_and_conquer(V, begin, mid);         //前面部分
    divide_and_conquer(V, mid + 1, end); //后面部分
}

int main() {
    vector<int> V;
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        V.push_back(i); //储存数据
    divide_and_conquer(V, 0, V.size() - 1); //使用分治算法
    cout << V << endl; //输出
    return 0;
}

