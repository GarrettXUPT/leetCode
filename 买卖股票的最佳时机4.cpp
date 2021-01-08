#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	使用动态规划解决该问题：一部分变量描述卖出状态，一部分变量描述买入状态
	buy[i][j]表示对于prices[0,...,i]价格内，恰好有j次交易，并且现在手上还有一只股票
	sell[i][j]表示对于prices[0,...,i]价格内，恰好有j次交易, 但手上不剩余股票
	
	对于买入过程buy[i][j],考虑当前手上持有的股票是否是第i天买入的
		1、若是第i天买入，那么第i - 1天时，手上没有股票 sell[i - 1][j] - price[i]
		2、若是第i - 1天买入，那么buy[i - 1][j]
	对于卖出过程，考虑股票是什么时间卖出的
		1、若是第i天卖出的buy[i - 1][j - 1] + price[i]
		2、若不是第i天卖出的，那么在第i - 1天，手上不持有股票即为sell[i - 1][j]
	边界条件：buy[0][0,...,k] sell[0][0,...,k]
		对于buy矩阵而言：仅在buy[0][0] = - price[0]是有值的，其他位置都为非法位置
		对于sell矩阵而言，sell[0][0] = 0; 其他位置都为非法位置
*/

int maxProfit(int k, vector<int>& prices) {
	if (prices.empty()) {
		return 0;
	}
	int len = prices.size();
	k = min(k, len / 2);  // 在n天最多可以进行n / 2次交易，所以可进行该步优化进行动态规划
	vector<vector<int>> buy(len, vector<int>(k + 1, 0));
	vector<vector<int>> sell(len, vector<int>(k + 1, 0));
	buy[0][0] = -prices[0];
	sell[0][0] = 0;
	for (int i = 1; i <= k; ++i) {
		buy[0][i] = sell[0][i] = INT16_MIN / 2;
	}
	
	for (int i = 1; i < len; ++i) {
		buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
		for (int j = 1; j <= k; ++j) {
			buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
			sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
		}
	}
	return *max_element(sell[len - 1].begin(), sell[len - 1].end());
}

int main() {
	vector<int> vec{ 2, 4, 1 };
	cout << maxProfit(2, vec) << endl;

}