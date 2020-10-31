#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::queue;
using std::vector;

int goX[4] = {1, -1, 0, 0};
int goY[4] = {0, 0, 1, -1};        //四个方向

struct orange {          //主要储存状态和感染时间
    int time = 0;
    int state = 0; //状态
    int pos_x = 0;
    int pos_y = 0;

    orange() = default;

    orange(int x_pos, int y_pos, int state) : pos_x(x_pos), pos_y(y_pos), state(state) {}
};

int BFS(vector<vector<orange>> &vec, int row, int col, queue<orange> &q, int num) {
    int res = 0;                             //计算时间
    while (!q.empty()) {                     //只要队列中还有数据
        orange Orange = q.front();            //获取队列中的数据
        res = std::max(Orange.time, res);       //因为可能遍历到一个已经感染过的橘子, 所以时间取大值
        for (auto i = 0; i < 4; i++) {          //遍历四个方向
            auto ora = vec[0][0];
            int nx = Orange.pos_x + goX[i];
            int ny = Orange.pos_y + goY[i];
            if(nx >= 0 && ny >= 0 && nx < col && ny < row)      //防止越界
                ora = vec[ny][nx];
            else
                continue;
            if (ora.state == 1) {
                vec[ny][nx].time = Orange.time + 1;               //更新数据
                vec[ny][nx].state = 2;
                ora.time = Orange.time + 1;
                num--;                                      //通过计算剩余的个数比遍历判断要更快
                q.push(ora);                                    //将更新后的对象存入
            }
        }
        q.pop();                                //队列数据弹出
    }
    if(num)
        return -1;                            //如果还有未被感染的橘子,返回-1
    return res;  //返回结果
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<orange>> OV;
    queue<orange> Queue; //利用队列来进行操作
    int num = 0;
    for (auto y = 0; y < row; y++) {  //获取输入
        vector<orange> V;
        for (auto x = 0; x < col; x++) {
            int state = 0;
            cin >> state;
            V.emplace_back(x, y, state); //存入容器
            if (state == 1)
                num++;
            if (state == 2)
                Queue.push(V.at(x));  //将statement为2的对象放入队列中
        }
        OV.push_back(V);
    }
    auto res = BFS(OV, row, col, Queue, num); //核心算法
    cout << res << endl;  //输出结果
    return 0;
}
