#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	��̬�滮
	dp[i][0]��ʾ��i�콻����ɺ�����û�й�Ʊʱ������
	dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices - fee)
	dp[i][1]��ʾ��i�콻����ɺ����ﻹ���й�Ʊʱ������
	dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices)
	
*/

int maxProfit(vector<int> prices, int fee) {
	int len = prices.size();
	// �����𰸱�
	vector<vector<int>> dp(len, vector<int>(2, 0));
	dp[0][0] = 0, dp[0][1] = -prices[0];
	for (int i = 1; i < len; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
	}
	return dp[len - 1][0];
}

int main() {
	vector<int> vec{ 1,3,2,8,4,9 };

	cout << maxProfit(vec, 2) << endl;
}