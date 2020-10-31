#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

int getMaxValue(int pre[][3]) //如果需要获取输入, 传入长度参数即可, 若为不定长, 可以选择传指针, 或者使用vector容器
{
    int end = 0;
    int row = 3, col = 3;
    int LeftMax = 0, UpMax = 0;
    int value[3] = {};      //如果是不定长,应该用memset或者for循环初始化为0
    for (auto i = 0; i < row; i++) {
        for (auto j = 0; j < col; j++) {
            LeftMax = 0;
            UpMax = 0;      //每次需要将储存的最大值重置为0
            if (i > 0) {
                UpMax = value[j]; //前一列的最大值
            }
            if (j > 0) {
                LeftMax = value[j - 1];//前一行的最大值
            }
            value[j] = std::max(UpMax, LeftMax) + pre[i][j];
            //仅需要储存行或者列在该数组对应的位置即可.最后到达末尾必然在value[col - 1]上.
        }
    }
    end = value[col - 1];
    return end;
}

int main() {
    int present[3][3] = {{1, 3, 1},
                         {1, 5, 1},
                         {4, 2, 1}}; //初始化数组, 若获取输入, 则需要先获取数据行列数, 再获取输入以赋值
    auto end = getMaxValue(present); //获得结果
    cout << end << endl;
    return 0;
}
