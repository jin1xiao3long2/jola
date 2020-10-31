//动态规划

#include <iostream>
#include <vector>

//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
//
//示例 1:
//输入: [7,1,5,3,6,4]
//输出: 5
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
//示例 2:
//输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
//
//限制：
//0 <= 数组长度 <= 10^5

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int max(int a, int b) {
    return a > b ? a : b;
}
/*
采用三维数组的解法：
建立三维的数组：dp[k][i][2]
其中k表示的是交易次数，i表示的是第几天，2表示的是有两种状态：手上没有股票/手上有股票
dp[k][i][0] 数组中的数字表示的是到了第i天，交易了k次，手上没有股票获得的最大利益
dp[k][i][1] 数组中的数字表示的是到了第i天，交易了k次，手上持有股票获得的最大利益
*/
int maxProfit(int k, vector<int> &prices) {
    if (!prices.size()) return 0;

    //如果k>n/2， 则等价于无限次交易，此时只需考虑累积的盈利
    if (k >= prices.size() / 2) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            int val = prices[i] - prices[i - 1];
            sum += (val > 0 ? val : 0);
        }
        return sum;
    }
    //考虑k<=n/2的情况，买入就算一次交易。
    vector<vector<vector<int> > > dp(k + 1, vector<vector<int> >(prices.size() + 1,
                                                                 vector<int>(2, 0)));//构造dp三维数组，持有不持有的收益均初始化为0
    for (int t = 0; t <= k; t++)
        dp[t][0][1] = -1000000; //0天t次交易，手上持有股票收益为较大负值
    for (int i = 0; i < prices.size(); i++)
        dp[0][i][1] = -1000000;//i天0次交易，手上持有股票收益为较大负值

    for (int t = 1; t <= k; t++) {
        for (int i = 1; i <= prices.size(); i++) {
            if (i == 1) {
                dp[t][i][0] = 0;
                dp[t][i][1] = -prices[i];
                continue;
            }
            //1.状态转移方程： i天t次交易现在手上不持有的收益需要考虑以下两种情况： 昨天不持有， 昨天持有今天卖出 。
            dp[t][i][0] = max(dp[t][i - 1][0], dp[t][i - 1][1] + prices[i]);

            //2.状态转移方程： i天t次交易现在手上持有的收益需要考虑以下两种情况： 昨天持有， 昨天不持有今天买入。
            dp[t][i][1] = max(dp[t - 1][i - 1][1], dp[t - 1][i - 1][0] - prices[i]);
        }
    }
    //3. 返回最终状态
    return dp[k][prices.size() - 1][0];
}

int main() {
    int n;
    cin >> n;
    int data;
    int time;
    vector<int> prices;
    for(int i = 0; i < n; i++){
        cin >> n;
        prices.push_back(data);
    }
    cin >> time;
    cout << maxProfit(time, prices) << endl;
    return 0;
}

