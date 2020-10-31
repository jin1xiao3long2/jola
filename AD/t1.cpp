//
// Created by XM on 2020/6/19.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>


using std::cout;
using std::endl;
using std::cin;

void Swap(int &lhs, int &rhs) { //用于交换用的辅助函数
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int QuickSort(int *arr, int low, int high) {  //快速排序算法
    int num = arr[high];      //选择枢轴
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= num) {
            i++;
            Swap(arr[i], arr[j]);
        }
    }
    Swap(arr[i + 1], arr[high]);
    return i + 1;            //返回枢轴位置
}


int RandomChoose(int *list, int low, int high) {                  //随机选择一个数作为枢轴
    srand(static_cast<unsigned int>(time(nullptr)));
    int i = (rand() % (high - low + 1)) + low;
    Swap(list[i], list[high]);
    return QuickSort(list, low, high);
}


int randomSort(int *list, int low, int high, int k) {             //递归分治
    if (low == high)  //剩余一个数
        return 0;
    int i = RandomChoose(list, low, high);    //获得枢轴下标值
    int j = i - low + 1;                      //获取在数据中的下标值
    if (k == j) return 0;                     //获得最小的k个数据(第一种情况)
    else if (k < j) return randomSort(list, low, i - 1, k);//(枢轴比k大,则从左边数据再次选择即可,k不变)
    else return randomSort(list, i + 1, high, k - j);//(枢轴比k大,则需要从右边数据选择前k-j个数据)
}


int main() {
    int i = 0, k = 0;
    std::cin >> i >> k;   //输入为数据长度和前k小数据
    int v[i];
    for (int j = 0; j < i; j++) {  //获取输入
        int m;
        cin >> m;
        v[j] = m;
    }
    auto end = randomSort(v, 0, i - 1, i - k + 1);  //算法完毕
    if (end == 0) {
        for (auto pos = 0; pos < k; pos++) {
            cout << v[pos] << " ";
        }
    }
    return 0;
}
