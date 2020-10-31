#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

//在给定的网格中，每个单元格可以有以下三个值之一：
//值 0 代表空单元格；
//值 1 代表新鲜橘子；
//值 2 代表腐烂的橘子。
//每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
//示例：
//
//输入：[[2,1,1],[1,1,0],[0,1,1]]
//输出：4


using std::cout;
using std::endl;
using std::cin;
using std::queue;
using std::vector;

struct pos {
    int x = 0;
    int y = 0;

    pos(int x, int y) : x(x), y(y) {}
};

vector<pos> Go;

struct orange {          //主要储存状态和感染时间
    int time = 0;
    int state = 0; //状态
    int pos_x = 0;
    int pos_y = 0;
    orange() = default;

    orange(int x_pos, int y_pos, int state) : pos_x(x_pos), pos_y(y_pos), state(state) {}
};

int BFS(vector<vector<orange>> &vec, queue<orange> &q, int row, int col, int num) {
    int res = 0;                             //储存结果
    while (!q.empty()) {                     //只要队列中还有数据(bfs固定操作)
        orange Orange = q.front();            //获取队列中的数据
        res = std::max(Orange.time, res);       //当旁边有多个腐烂的橘子
        for (auto i = 0; i < 4; i++) {          //遍历四个方向
            int nx = Orange.pos_x + Go[i].x;
            int ny = Orange.pos_y + Go[i].y;
            auto ora = vec[0][0];
            if (nx >= 0 && ny >= 0 && nx < col && ny < row)      //防止越界
                ora = vec[ny][nx];
            else
                continue;
            if (ora.state == 1) {
                vec[ny][nx].time = Orange.time + 1;               //更新数据
                vec[ny][nx].state = 2;
                ora.time = Orange.time + 1;
                num--;
                q.push(ora);                                    //对象更新完毕,存入
            }
        }
        q.pop();                                //恢复数据
    }
    if (num)
        return -1;                            //无法全部感染,则返回-1
    return res;  //返回
}

int main() {
    Go.emplace_back(1, 0);
    Go.emplace_back(-1, 0);
    Go.emplace_back(0, 1);
    Go.emplace_back(0, -1);
    int r, l;
    cin >> r >> l;
    vector<vector<orange>> v;
    queue<orange> queue; //利用队列来进行操作
    int num = 0;
    for (auto y = 0; y < r; y++) {  //获取输入
        vector<orange> V;
        for (auto x = 0; x < l; x++) {
            int state = 0;
            cin >> state;
            V.emplace_back(x, y, state); //存入容器
            if (state == 1)
                num++;
            if (state == 2)
                queue.push(V.at(x));  //将statement为2的对象放入队列中
        }
        v.push_back(V);
    }
    auto res = BFS(v, queue, r, l, num); //核心算法
    cout << res << endl;  //输出结果
    return 0;
}
